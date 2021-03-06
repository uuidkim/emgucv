//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2019 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#include "xobjdetect_c.h"

cv::xobjdetect::WBDetector* cveWBDetectorCreate(cv::Ptr<cv::xobjdetect::WBDetector>** sharedPtr)
{
	cv::Ptr<cv::xobjdetect::WBDetector> ptr = cv::xobjdetect::WBDetector::create();
	*sharedPtr = new cv::Ptr<cv::xobjdetect::WBDetector>(ptr);
	return ptr.get();
}
void cveWBDetectorRead(cv::xobjdetect::WBDetector* detector, cv::FileNode* node)
{
	detector->read(*node);
}
void cveWBDetectorWrite(cv::xobjdetect::WBDetector* detector, cv::FileStorage* fs)
{
	detector->write(*fs);
}
void cveWBDetectorTrain(cv::xobjdetect::WBDetector* detector, cv::String* posSamples, cv::String* negImgs)
{
	detector->train(*posSamples, *negImgs);
}
void cveWBDetectorDetect(cv::xobjdetect::WBDetector* detector, cv::Mat* img, std::vector<cv::Rect>* bboxes, std::vector<double>* confidences)
{
	detector->detect(*img, *bboxes, *confidences);
}
void cveWBDetectorRelease(cv::xobjdetect::WBDetector** detector, cv::Ptr<cv::xobjdetect::WBDetector>** sharedPtr)
{
	delete *sharedPtr;
	*detector = 0;
	*sharedPtr = 0;
}
