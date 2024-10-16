# Install script for directory: /Users/chris/sdl3/SDL

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/chris/sdl3/build/sdl3.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/chris/sdl3/build/libSDL3.0.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3.0.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3.0.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3.0.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/chris/sdl3/build/libSDL3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/chris/sdl3/build/libSDL3_test.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3_test.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3_test.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL3_test.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3headersTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3headersTargets.cmake"
         "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3headersTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3headersTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3headersTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3headersTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3sharedTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3sharedTargets.cmake"
         "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3sharedTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3sharedTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3sharedTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3sharedTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3sharedTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3testTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3testTargets.cmake"
         "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3testTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3testTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3/SDL3testTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3testTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES "/Users/chris/sdl3/build/CMakeFiles/Export/35815d1d52a6ea1175d74784b559bdb6/SDL3testTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL3" TYPE FILE FILES
    "/Users/chris/sdl3/build/SDL3Config.cmake"
    "/Users/chris/sdl3/build/SDL3ConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL3" TYPE FILE FILES
    "/Users/chris/sdl3/SDL/include/SDL3/SDL.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_assert.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_atomic.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_audio.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_begin_code.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_bits.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_blendmode.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_camera.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_clipboard.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_close_code.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_copying.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_cpuinfo.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_dialog.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_egl.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_endian.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_error.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_events.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_filesystem.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_gamepad.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_guid.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_haptic.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_hidapi.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_hints.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_init.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_intrin.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_iostream.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_joystick.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_keyboard.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_keycode.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_loadso.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_locale.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_log.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_main.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_main_impl.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_messagebox.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_metal.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_misc.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_mouse.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_mutex.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_oldnames.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengl.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengl_glext.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles2.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles2_gl2.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles2_gl2ext.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles2_gl2platform.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_opengles2_khrplatform.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_pen.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_pixels.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_platform.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_platform_defines.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_power.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_properties.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_rect.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_render.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_scancode.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_sensor.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_stdinc.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_storage.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_surface.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_system.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_thread.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_time.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_timer.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_touch.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_version.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_video.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_vulkan.h"
    "/Users/chris/sdl3/build/include/SDL3/SDL_revision.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL3" TYPE FILE FILES
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_assert.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_common.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_compare.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_crc32.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_font.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_fuzzer.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_harness.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_log.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_md5.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_memory.h"
    "/Users/chris/sdl3/SDL/include/SDL3/SDL_test_random.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/SDL3" TYPE FILE FILES "/Users/chris/sdl3/SDL/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/chris/sdl3/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
