import sys, time
import numpy as np
from scipy.ndimage import filters
import cv2
import roslib
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class image_feature:

    def __init__(self):
        self.bridge = CvBridge()
        self.subscriber = rospy.Subscriber("/camera/image_raw",
            Image, self.callback,  queue_size = 1)


    def callback(self, ros_data):
        print('processing')
        cv_image = self.bridge.imgmsg_to_cv2(ros_data, "bgr8")
        img_gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        circles = cv2.HoughCircles(img_gray, cv2.HOUGH_GRADIENT, 1.2, 100)

        if circles is not None:
            # convert the (x, y) coordinates and radius of the circles to integers
            circles = np.round(circles[0, :]).astype("int")
            # loop over the (x, y) coordinates and radius of the circles
            for (x, y, r) in circles:
                # draw the circle in the output image, then draw a rectangle
                # corresponding to the center of the circle
                cv2.circle(output, (x, y), r, (0, 255, 0), 4)
                cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
            # show the output image
            print("here")
            cv2.imread("output.png", np.hstack([cv_image, output]))
            cv2.waitKey(0)

def main(args):
    ic = image_feature()
    rospy.init_node('gazebo', anonymous=True)

if __name__ == '__main__':
    main(sys.argv)