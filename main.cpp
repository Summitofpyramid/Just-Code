//
//  main.cpp
//  Configuration
//
//  Created by Dougalas Michael on 16/3/21.
//  Copyright © 2016年 Johnson. All rights reserved.
//

#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>
#include <string>
#include <vector>
//#include "descriptor.h"
#include "ReidDescriptor.h"
#include "histdescriptor.h"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[])
{
    
    
    // /Users/dougalasmichael/Documents/ReidDatasets/prid_2011/single_shot
    string inputFolder  = "/Users/dougalasmichael/Documents/ReidDatasets/prid_2011/multi_shot/";
    //  string inputFolder  = "/Users/dougalasmichael/Documents/ReidDatasets/VIPeR/";
    
    
    string defaultProbesFilename  = "probes.txt";
    string defaultGalleryFilename = "gallery.txt";
    string defaultOutputFilename  = "table.csv";
    
    vector<string> List,Singleton; //List is the list of all the images in cam_a
    vector< vector<string> > ClassedList; //
    
    ifstream imgList(inputFolder+defaultGalleryFilename );
    string  line;
    while(getline(imgList,line))
    {
        List.push_back(line);
    
    }
    
    Singleton.push_back(List[0]);
    for(vector< vector<string> >::size_type iter = 1;iter<List.size();++iter)
    {
     //   cout<<List[iter]<<endl;
        
        string Id_previous = List[iter-1].substr(14,4);
        string Id_present = List[iter].substr(14,4);
        if (Id_previous == Id_present )
        
            Singleton.push_back(List[iter]);
  
        else
        {
        
        ClassedList.push_back(Singleton);
        Singleton.clear();
            Singleton.push_back(List[iter]);
        }
        
        if (iter ==(List.size()-1))
        ClassedList.push_back(Singleton);
        
    }
    
    
    cout<<ClassedList.size()<<endl;
    for(vector< vector<string> >::size_type iter1 = 0;iter1<ClassedList.size();++iter1)
    {
        cout<<ClassedList[iter1].size()<<endl;
    }
    
    }