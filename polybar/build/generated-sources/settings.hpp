#pragma once

#include <cstdio>
#include <string>
#include <vector>

#define APP_NAME "polybar"
#define APP_VERSION "3.4.1"

#define ENABLE_ALSA 1
#define ENABLE_MPD 1
#define ENABLE_NETWORK 1
#define WITH_LIBNL 0
#define WIRELESS_LIB "wireless-tools"
#define ENABLE_I3 1
#define ENABLE_CURL 1
#define ENABLE_PULSEAUDIO 1

#define WITH_XRANDR 1
#define WITH_XCOMPOSITE 1
#define WITH_XKB 1
#define WITH_XRM 1
#define WITH_XCURSOR 1

#if WITH_XRANDR
#define WITH_XRANDR_MONITORS 1
#else
#define WITH_XRANDR_MONITORS 0
#endif

#if WITH_XKB
#define ENABLE_XKEYBOARD 1
#else
#define ENABLE_XKEYBOARD 0
#endif

#define XPP_EXTENSION_LIST xpp::randr::extension, xpp::composite::extension, xpp::xkb::extension

#define DEBUG_LOGGER

#if DEBUG
/* #undef DEBUG_LOGGER_VERBOSE */
/* #undef DEBUG_HINTS */
/* #undef DEBUG_WHITESPACE */
/* #undef DEBUG_SHADED */
/* #undef DEBUG_FONTCONFIG */
#endif

static const size_t EVENT_SIZE = 64;

static const int SIGN_PRIORITY_CONTROLLER{1};
static const int SIGN_PRIORITY_SCREEN{2};
static const int SIGN_PRIORITY_BAR{3};
static const int SIGN_PRIORITY_RENDERER{4};
static const int SIGN_PRIORITY_TRAY{5};

static const int SINK_PRIORITY_BAR{1};
static const int SINK_PRIORITY_SCREEN{2};
static const int SINK_PRIORITY_TRAY{3};
static const int SINK_PRIORITY_MODULE{4};

static constexpr const char* ALSA_SOUNDCARD{"default"};
static constexpr const char* BSPWM_SOCKET_PATH{"/tmp/bspwm_0_0-socket"};
static constexpr const char* BSPWM_STATUS_PREFIX{"W"};
static constexpr const char* CONNECTION_TEST_IP{"8.8.8.8"};
static constexpr const char* PATH_ADAPTER{"/sys/class/power_supply/%adapter%"};
static constexpr const char* PATH_BACKLIGHT{"/sys/class/backlight/%card%"};
static constexpr const char* PATH_BATTERY{"/sys/class/power_supply/%battery%"};
static constexpr const char* PATH_CPU_INFO{"/proc/stat"};
static constexpr const char* PATH_MEMORY_INFO{"/proc/meminfo"};
static constexpr const char* PATH_MESSAGING_FIFO{"/tmp/polybar_mqueue.%pid%"};
static constexpr const char* PATH_TEMPERATURE_INFO{"/sys/class/thermal/thermal_zone%zone%/temp"};

static constexpr const char* BUILDER_SPACE_TOKEN{"%__"};

const auto version_details = [](const std::vector<std::string>& args) {
  for (auto&& arg : args) {
    if (arg.compare(0, 3, "-vv") == 0)
      return true;
  }
  return false;
};

// clang-format off
const auto print_build_info = [](bool extended = false) {
  printf("%s %s\n\n", APP_NAME, APP_VERSION);
  printf("Features: %calsa %ccurl %ci3 %cmpd %cnetwork(%s) %cpulseaudio %cxkeyboard\n",
    (ENABLE_ALSA       ? '+' : '-'),
    (ENABLE_CURL       ? '+' : '-'),
    (ENABLE_I3         ? '+' : '-'),
    (ENABLE_MPD        ? '+' : '-'),
    (ENABLE_NETWORK    ? '+' : '-'),
    WIRELESS_LIB,
    (ENABLE_PULSEAUDIO ? '+' : '-'),
    (ENABLE_XKEYBOARD  ? '+' : '-'));
  if (extended) {
    printf("\n");
    printf("X extensions: %crandr (%cmonitors) %ccomposite %cxkb %cxrm %cxcursor\n",
      (WITH_XRANDR            ? '+' : '-'),
      (WITH_XRANDR_MONITORS   ? '+' : '-'),
      (WITH_XCOMPOSITE        ? '+' : '-'),
      (WITH_XKB               ? '+' : '-'),
      (WITH_XRM               ? '+' : '-'),
      (WITH_XCURSOR           ? '+' : '-'));
    printf("\n");
    printf("Build type: Release\n");
    printf("Compiler: /usr/bin/g++\n");
    printf("Compiler flags:  -Wall -Wextra -Wpedantic -O3 -DNDEBUG\n");
    printf("Linker flags:  \n");
  }
};
// clang-format on

// vim:ft=cpp
