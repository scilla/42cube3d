sudo apt-get install gcc make clang lldb xorg libxext-dev libbsd-dev zlib1g-dev libssl-dev libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev libgles2-mesa-dev
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0