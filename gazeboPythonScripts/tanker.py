import sys, time
import numpy as np
from scipy.ndimage import filters
import cv2
import roslib
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from threading import Thread
from time import sleep
from gazebo_msgs.msg import ModelState
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import math
import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 4444

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP

pitch = yaw = 0.0

rospy.init_node('gazebo', anonymous=True)

pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)

for i in range(50, 10000):
    sock.sendto(str(i), (UDP_IP, UDP_PORT))

    quaternion = quaternion_from_euler(i%90, pitch, yaw)

    modelState = ModelState()
    modelState.model_name = 'tanker'
    modelState.pose.position.x = i
    modelState.pose.position.y = 0
    modelState.pose.position.z = 8
    modelState.pose.orientation.x = quaternion[0]
    modelState.pose.orientation.y = quaternion[1]
    modelState.pose.orientation.z = quaternion[2]
    modelState.pose.orientation.w = quaternion[3]
    pub_modelstate.publish(modelState)
    sleep(0.1)
print('finished')
try:
    rospy.spin()
except KeyboardInterrupt:
    print("Shutting down vison node.")
