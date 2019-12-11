#RCNODE
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rcnode'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'rcnode'
sleep 1


#BETAWORLDARM
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/files/innermodel/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'rcis betaWorldArm.xml'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'betaWorldArm'
sleep 1

#ROBOTPICKER
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/components/Robotica/robotpicker/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'bin/MyFirstComp --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'robotpicker'
sleep 1

#MISSION
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/components/Robotica/mission/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'bin/mission --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'MISSION'

#APRILTAGS
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession
sess=`qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.activeSessionId`
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'cd ~/robocomp/components/robocomp-robolab/components/detection/apriltagsComp/'
qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.runCommand 'bin/AprilTagsComp --Ice.Config=etc/config'
qdbus org.kde.yakuake /yakuake/tabs org.kde.yakuake.setTabTitle $sess 'AprilTagsComp'
sleep 1



# qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.removeSession $INITIAL_ID
