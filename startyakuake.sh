#RCNODE
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rcnode'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'rcnode'
sleep 1

# RCIS
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/files/innermodel/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rcis simpleworld.xml'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'rcis'
sleep 1

# SIMPLEWORLD
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/files/innermodel/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rcis simpleworld.xml'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'simpleworld'
sleep 1

# ASPIRADOR
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/components/Robotica/beta-robotica-class/aspirador/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'bin/aspirador --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'aspirador'
sleep 1


#CHOCAMEM
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/components/Robotica/chocamem'
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rm -f CMakeCache.txt'
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cmake .'
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'killall -9 ChocaMem; make -j4; bin/ChocaMem --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'killall -9 ChocaMem; bin/ChocaMem --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'ChocaMem'
sleep 1

# joystickComp
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
# sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd /home/borja/robocomp/components/robocomp-robolab/components/joystickComp/bin'
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand './joystickComp --Ice.Config=/home/robocomp/robocomp/components/robocomp-ursus-rockin/etc/joystick.conf'
# qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'joystick'
# sleep 1

# AprilTags
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
# sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd /home/borja/robocomp/components/robocomp-robolab/components/apriltagsComp'
# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'bin/apriltagscomp --Ice.Config=/home/robocomp/robocomp/components/robocomp-ursus-rockin/etc/apriltags.conf'
# qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'april'
# sleep 1


# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.removeSession $INITIAL_ID