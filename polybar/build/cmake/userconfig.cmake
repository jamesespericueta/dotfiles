set(USER_CONFIG_HOME "$ENV{XDG_CONFIG_HOME}")
if(NOT USER_CONFIG_HOME)
  set(USER_CONFIG_HOME "$ENV{HOME}/.config")
endif()
set(USER_CONFIG_HOME "${USER_CONFIG_HOME}/polybar")

file(INSTALL "/home/james/src/polybar/config"
  DESTINATION "${USER_CONFIG_HOME}")
