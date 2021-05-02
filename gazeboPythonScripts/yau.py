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
import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 4444

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

class image_feature:

    def __init__(self):
        self.pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)
        self.currentPosition = 0.0
        self.bridge = CvBridge()
        self.subscriber = rospy.Subscriber("/camera/image_raw",
            Image, self.callback,  queue_size = 1)


    def callback(self, ros_data):
        data, addr = sock.recvfrom(1024)
        print(data)

        cv_image = self.bridge.imgmsg_to_cv2(ros_data, "bgr8")
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        circles = cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT,2,400, param1=50,param2=10,minRadius=10,maxRadius=100)

        if self.currentPosition - int(data) < 10 :
            print(circles)
            if circles is not None:
                xPos = -5.983*10**-7*circles[0][0][2]**5 + 0.0001086*circles[0][0][2]**4 - 0.00788*circles[0][0][2]**3 + 0.292*circles[0][0][2]**2 - 5.812*circles[0][0][2] + 59
                if xPos > 10:
                    self.currentPosition = self.currentPosition + 1
                else:
                    self.currentPosition = self.currentPosition + 0.5
                modelState = ModelState()
                modelState.model_name = 'yau'
                modelState.pose.position.x = self.currentPosition
                modelState.pose.position.y = 0
                modelState.pose.position.z = 5
                self.pub_modelstate.publish(modelState)
            else:
                self.currentPosition = self.currentPosition + 0.01

                modelState = ModelState()
                modelState.model_name = 'yau'
                modelState.pose.position.x = self.currentPosition
                modelState.pose.position.y = 0
                modelState.pose.position.z = 5
                self.pub_modelstate.publish(modelState)

        else:
            modelState = ModelState()
            modelState.model_name = 'yau'
            modelState.pose.position.x = self.currentPosition
            modelState.pose.position.y = 0
            modelState.pose.position.z = 5
            self.pub_modelstate.publish(modelState)
            self.currentPosition = self.currentPosition + 1


def main(args):
    rospy.init_node('gazebo', anonymous=True)
    ic = image_feature()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down vison node.")

    
if __name__ == '__main__':
    main(sys.argv)
