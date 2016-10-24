#include <QCoreApplication>
#include <iostream>

#include "webcamstream.h"
#include "onistream.h"
#include "colordetector.h"
#include "utils.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
//    return a.exec();


//    WebcamStream webcam;

//    OniStream oniStream;
    OniStream oniStream("../onistream_test.oni");
    ColorDetector colorDetector;
//    colorDetector.setColorValues(oniStream);
    colorDetector.setColorValues(105, 135, 25, 255, 25, 255); //magic numbers from running set color values with webcam...


    if (oniStream.isOpened())
    {
        printf("OniStream Opened Successfully\n");
    }

    if (oniStream.isOpened())
    {
        while (true)
        {
            cv::Mat depthFrame, colorFrame;
            oniStream.next(depthFrame, colorFrame);

            if (colorFrame.data != NULL && depthFrame.size !=NULL){

                cv::Mat mask;
                colorDetector.run(colorFrame, mask);

//                cv::Mat dst;
//                cv::bitwise_and(colorFrame, colorFrame, dst, mask);
//                cv::imshow("Color Image", dst);
//                cv::imshow("Original Color", colorFrame);

                cv::Mat dst2;
                cv::Mat cropped = depthFrame(cv::Rect(0,0,512,424));

                cv::bitwise_and(cropped, cropped, dst2, mask);
                cv::imshow("Depth Image", dst2);

//                cv::imshow("Original Depth", cropped);
            }

            if (cv::waitKey(20) >=0 ) break;
        }
    }


//    WebcamStream webcam;
//    ColorDetector colorDetector;

////    colorDetector.setColorValues(webcam);
////    lower_blue = np.array([110,50,50]);
////    upper_blue = np.array([130,255,255]);

//    colorDetector.setColorValues(110, 130, 50, 255, 50, 255); //magic numbers from running set color values with webcam...

//    if (webcam.isOpened())
//    {

//        while(true)
//        {
//            cv::Mat frame;
//            cv::Mat mask;
//            webcam.next(frame);
//            colorDetector.run(frame, mask);

//            cv::Mat dst;
//            cv::bitwise_and(frame, frame, dst, thresholded);
//            cv::imshow("Thresholded Image", dst);
//            if (cv::waitKey(20) >= 0) break;
//        }

//    }

}
