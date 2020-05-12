/*
 * Copyright (C) 2019-present Alibaba Inc. All rights reserved.
 * Author: Kraken Team.
 */

import 'dart:async';

import 'package:flutter/rendering.dart';
import 'package:kraken/element.dart';
import 'package:kraken_video_player/kraken_video_player.dart';

const String VIDEO = 'VIDEO';

List<VideoPlayerController> _videoControllers = [];

class VideoElement extends Element {
  VideoPlayerController controller;

  String _src;
  String get src => _src;
  set src(String value) {
    if (_src != value) {
      bool needDispose = _src != null;
      _src = value;

      if (needDispose) {
        controller.dispose().then((_) {
          _videoControllers.remove(controller);
          _removeVideoBox();

          _createVideoBox();
        });
      } else {
        _createVideoBox();
      }
    }
  }

  static const String DEFAULT_WIDTH = '300px';
  static const String DEFAULT_HEIGHT = '150px';

  VideoElement(int targetId, Map<String, dynamic> props, List<String> events)
      : super(
          targetId: targetId,
          defaultDisplay: 'block',
          allowChildren: false,
          tagName: VIDEO,
          properties: props,
          events: events,
        );

  Future<int> createVideoPlayer(String src) {
    Completer<int> completer = new Completer();

    if (src.startsWith('//') ||
        src.startsWith('http://') ||
        src.startsWith('https://')) {
      controller = VideoPlayerController.network(src.startsWith('//') ? 'https:' + src : src);
    } else if (src.startsWith('file://')) {
      controller = VideoPlayerController.file(src);
    } else {
      // Fallback to asset video
      controller = VideoPlayerController.asset(src);
    }

    _src = src;

    controller.setLooping(properties.containsKey('loop'));
    controller.onCanPlay = onCanPlay;
    controller.onCanPlayThrough = onCanPlayThrough;
    controller.onPlay = onPlay;
    controller.onPause = onPause;
    controller.onSeeked = onSeeked;
    controller.onSeeking = onSeeking;
    controller.onEnded = onEnded;
    controller.onError = onError;
    controller.initialize().then((int textureId) {
      if (properties.containsKey('muted')) {
        controller.setMuted(true);
      }

      completer.complete(textureId);
    });

    _videoControllers.add(controller);

    return completer.future;
  }

  void addVideoBox(int textureId) {
    if (properties['src'] == null) {
      TextureBox box = TextureBox(textureId: 0);
      addChild(box);
      return;
    }

    TextureBox box = TextureBox(textureId: textureId);

    addChild(box);

    if (properties.containsKey('autoplay')) {
      controller.play();
    }
  }

  void _createVideoBox() {
    createVideoPlayer(_src).then((textureId) {
      addVideoBox(textureId);
    });
  }

  void _removeVideoBox() {
    renderPadding.child = null;
  }

  Future<Map<String, dynamic>> getVideoDetail() async {
    final Completer<Map<String, dynamic>> detailCompleter =
        Completer<Map<String, dynamic>>();
    RendererBinding.instance.addPostFrameCallback((Duration timeout) {
      var value = controller.value;
      var duration = value.duration;

      if (renderPadding.child != null) {
        Size size = renderPadding.size;
        detailCompleter.complete({
          'videoWidth': size.width,
          'videoHeight': size.height,
          'src': _src,
          'duration': '${duration.inSeconds}',
          'volume': value.volume,
          'position': value.position.inSeconds,
          'paused': !value.isPlaying,
        });
      }
    });
    return detailCompleter.future;
  }

  onCanPlay() async {
    Event event = Event('canplay', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onCanPlayThrough() async {
    Event event = Event('canplaythrough', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onEnded() async {
    Event event = Event('ended', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onError(int code, String error) {
    Event event = Event('error', EventInit());
    event.detail = {'code': code, 'message': error};
    dispatchEvent(event);
  }

  onPause() async {
    Event event = Event('pause', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onPlay() async {
    Event event = Event('play', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onSeeked() async {
    Event event = Event('seeked', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onSeeking() async {
    Event event = Event('seeking', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  onVolumeChange() async {
    Event event = Event('volumechange', EventInit());
    event.detail = await getVideoDetail();
    dispatchEvent(event);
  }

  @override
  method(String name, List args) {
    if (controller == null) {
      return;
    }

    switch (name) {
      case 'play':
        controller.play();
        break;
      case 'pause':
        controller.pause();
        break;
      default:
        super.method(name, args);
    }
  }

  @override
  void setProperty(String key, value) {
    super.setProperty(key, value);
    if (key == 'src') {
      src = value.toString();
    }
  }

  // dispose all video player when Dart VM is going to shutdown
  static Future<void> disposeVideos() async {
    for (int i = 0; i < _videoControllers.length; i++) {
      await _videoControllers[i].dispose();
    }
    _videoControllers.clear();
  }
}
