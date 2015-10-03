/**************************************************************************
* Name : Multi-camera Multi-target Tracking in PSN
* Author : HAANJU.YOO
* Initial Date : 2013.08.29
* Last Update : 2013.08.29
* Version : 0.9
***************************************************************************
*                                            ....
*                                           W$$$$$u
*                                           $$$$F**+           .oW$$$eu
*                                           ..ueeeWeeo..      e$$$$$$$$$
*                                       .eW$$$$$$$$$$$$$$$b- d$$$$$$$$$$W
*                           ,,,,,,,uee$$$$$$$$$$$$$$$$$$$$$ H$$$$$$$$$$$~
*                        :eoC$$$$$$$$$$$C""?$$$$$$$$$$$$$$$ T$$$$$$$$$$"
*                         $$$*$$$$$$$$$$$$$e "$$$$$$$$$$$$$$i$$$$$$$$F"
*                         ?f"!?$$$$$$$$$$$$$$ud$$$$$$$$$$$$$$$$$$$$*Co
*                         $   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                 !!!!m.*eeeW$$$$$$$$$$$f?$$$$$$$$$$$$$$$$$$$$$$$$$$$$$U
*                 !!!!!! !$$$$$$$$$$$$$$  T$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                  *!!*.o$$$$$$$$$$$$$$$e,d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:
*                 "eee$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$C
*                b ?$$$$$$$$$$$$$$**$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!
*                Tb "$$$$$$$$$$$$$$*uL"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
*                 $$o."?$$$$$$$$F" u$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                  $$$$en ```    .e$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
*                   $$$B*  =*"?.e$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$F
*                    $$$W"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
*                     "$$$o#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
*                    R: ?$$$W$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" :!i.
*                     !!n.?$???""``.......,``````"""""""""""``   ...+!!!
*                      !* ,+::!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*`
*                      "!?!!!!!!!!!!!!!!!!!!~ !!!!!!!!!!!!!!!!!!!~`
*                      +!!!!!!!!!!!!!!!!!!!! !!!!!!!!!!!!!!!!!!?!`
*                    .!!!!!!!!!!!!!!!!!!!!!' !!!!!!!!!!!!!!!, !!!!
*                   :!!!!!!!!!!!!!!!!!!!!!!' !!!!!!!!!!!!!!!!! `!!:
*                .+!!!!!!!!!!!!!!!!!!!!!~~!! !!!!!!!!!!!!!!!!!! !!!.
*               :!!!!!!!!!!!!!!!!!!!!!!!!!.`:!!!!!!!!!!!!!!!!!:: `!!+
*               "~!!!!!!!!!!!!!!!!!!!!!!!!!!.~!!!!!!!!!!!!!!!!!!!!.`!!:
*                   ~~!!!!!!!!!!!!!!!!!!!!!!! ;!!!!~` ..eeeeeeo.`+!.!!!!.
*                 :..    `+~!!!!!!!!!!!!!!!!! :!;`.e$$$$$$$$$$$$$u .
*                 $$$$$$beeeu..  `````~+~~~~~" ` !$$$$$$$$$$$$$$$$ $b
*                 $$$$$$$$$$$$$$$$$$$$$UU$U$$$$$ ~$$$$$$$$$$$$$$$$ $$o
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$. $$$$$$$$$$$$$$$~ $$$u
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$! $$$$$$$$$$$$$$$ 8$$$$.
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$X $$$$$$$$$$$$$$`u$$$$$W
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$! $$$$$$$$$$$$$".$$$$$$$:
*                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  $$$$$$$$$$$$F.$$$$$$$$$
*                 ?$$$$$$$$$$$$$$$$$$$$$$$$$$$$f $$$$$$$$$$$$' $$$$$$$$$$.
*                  $$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$  $$$$$$$$$$!
*                  "$$$$$$$$$$$$$$$$$$$$$$$$$$$ ?$$$$$$$$$$$$  $$$$$$$$$$!
*                   "$$$$$$$$$$$$$$$$$$$$$$$$Fib ?$$$$$$$$$$$b ?$$$$$$$$$
*                     "$$$$$$$$$$$$$$$$$$$$"o$$$b."$$$$$$$$$$$  $$$$$$$$'
*                    e. ?$$$$$$$$$$$$$$$$$ d$$$$$$o."?$$$$$$$$H $$$$$$$'
*                   $$$W.`?$$$$$$$$$$$$$$$ $$$$$$$$$e. "??$$$f .$$$$$$'
*                  d$$$$$$o "?$$$$$$$$$$$$ $$$$$$$$$$$$$eeeeee$$$$$$$"
*                  $$$$$$$$$bu "?$$$$$$$$$ 3$$$$$$$$$$$$$$$$$$$$*$$"
*                 d$$$$$$$$$$$$$e. "?$$$$$:`$$$$$$$$$$$$$$$$$$$$8
*         e$$e.   $$$$$$$$$$$$$$$$$$+  "??f "$$$$$$$$$$$$$$$$$$$$c
*        $$$$$$$o $$$$$$$$$$$$$$$F"          `$$$$$$$$$$$$$$$$$$$$b.0
*       M$$$$$$$$U$$$$$$$$$$$$$F"              ?$$$$$$$$$$$$$$$$$$$$$u
*       ?$$$$$$$$$$$$$$$$$$$$F                   "?$$$$$$$$$$$$$$$$$$$$u
*        "$$$$$$$$$$$$$$$$$$"                       ?$$$$$$$$$$$$$$$$$$$$o
*          "?$$$$$$$$$$$$$F                            "?$$$$$$$$$$$$$$$$$$
*             "??$$$$$$$F                                 ""?3$$$$$$$$$$$$F
*                                                       .e$$$$$$$$$$$$$$$$'
*                                                      u$$$$$$$$$$$$$$$$$
*                                                     `$$$$$$$$$$$$$$$$"
*                                                      "$$$$$$$$$$$$F"
*                                                        ""?????""
*
***************************************************************************
*
* Using DDK dataset
*
**************************************************************************/
#include "stdafx.h"
#include <iostream>
#include "PSNWhere.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// argument handling
#ifdef _UNICODE
	std::wstring wstrDatasetPath(argv[1]);
	std::string strDatasetPath(wstrDatasetPath.begin(), wstrDatasetPath.end());
#else
	std::string strDatasetPath = argv[1];
#endif
	char inputFilePath[300];

	static const int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	std::vector<int> parameters(arr, arr + sizeof(arr)/sizeof(arr[0]));
	
	for (int configIdx = 0; configIdx < parameters.size(); configIdx++)
	{
		stConfiguration_Associator3D curConfig3D;
		curConfig3D.nProcWindowSize = -1;
		curConfig3D.nKBestSize = parameters[configIdx];
		curConfig3D.nMaxTrackInOptimization = -1;
		curConfig3D.nMaxTrackInUnconfirmedTrackTree = -1;
		curConfig3D.nNumFrameForConfirmation = -1;

		for (int expIdx = 0; expIdx < NUM_EXPERIMENTS; expIdx++)
		{
			// show experiment label
			cv::Mat expLabel = cv::Mat::zeros(40, 60, CV_8UC1);
			cv::putText(expLabel, std::to_string(expIdx), cv::Point(0, 30), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255));
			cv::imshow("experiment label", expLabel);

			/////////////////////////////////////////////////////////////////
			// INITIALIZATION
			/////////////////////////////////////////////////////////////////	
			CPSNWhere psnWhere = CPSNWhere();
			psnWhere.Initialize(strDatasetPath, &curConfig3D);
			cv::Mat inputFrame[NUM_CAM];

			// PETS2009 S2L1
			int frameIdxStart = 0;			
			int frameIdxEnd = 794;
	
			/////////////////////////////////////////////////////////////////
			// MAIN LOOP
			/////////////////////////////////////////////////////////////////
			for (int frameIdx = frameIdxStart; frameIdx <= frameIdxEnd; frameIdx++) 
			{
				//---------------------------------------------------
				// FRAME GRABBING
				//---------------------------------------------------		
				for (int camIdx = 0; camIdx < NUM_CAM; camIdx++) 
				{
					unsigned int curCamID = CAM_ID[camIdx];				
					if (PSN_INPUT_TYPE)
						sprintf_s(inputFilePath, sizeof(inputFilePath), "%s\\View_%03d\\frame_%04d.jpg", strDatasetPath.c_str(), curCamID, frameIdx);						
					else 
						sprintf_s(inputFilePath, sizeof(inputFilePath), "%s\\%d_%d.jpg", strDatasetPath.c_str(), curCamID, frameIdx);
					inputFrame[camIdx] = cv::imread(inputFilePath, cv::IMREAD_COLOR);
					if (!inputFrame[camIdx].data) 
					{
						std::cout << "Can't open the input frame" << std::endl;
						inputFrame[camIdx].release();
						return -1;
					}
				}
		
				//---------------------------------------------------
				// TRACKING
				//---------------------------------------------------
				psnWhere.TrackPeople(inputFrame, frameIdx);

				//---------------------------------------------------
				// MEMORY CLEARING
				//---------------------------------------------------
				for (int camIdx = 0; camIdx < NUM_CAM; camIdx++) { inputFrame[camIdx].release(); }
			}
	
			/////////////////////////////////////////////////////////////////
			// TERMINATION
			/////////////////////////////////////////////////////////////////
			psnWhere.Finalize();
		}
	}

	return 0;
}

//()()
//('')HAANJU.YOO
