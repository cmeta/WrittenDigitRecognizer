//
//  TextDetection.hpp
//  A4PaperScan
//
//  Created by 王 颖豪 on 6/15/17.
//  Copyright © 2017 TSK. All rights reserved.
//

#ifndef TextDetection_hpp
#define TextDetection_hpp

#include "headers.h"
#include "selective_search.hpp"
using namespace std;
using namespace cimg_library;

vector<ss::Rect> text_detection(CImg<> image);

void filterBySize(const CImg<>& image, vector<ss::Rect>& proposals);

void filterByAspectRatio(vector<ss::Rect>& p);

void filterByDuplicate(vector<ss::Rect>& p);

void padRegion(const CImg<>& image, vector<ss::Rect>& p, int padding);

inline void Rectangle(CImg<unsigned char>& img, ss::Rect r) {
    
    for (int x = r.x; x < r.x + r.width; x++) {
        int y1 = r.y;
        int y2 = r.y + r.height;
        
        img(x, y1, 0) = 0;
        img(x, y2, 0) = 0;
        img(x, y1, 1) = 0;
        img(x, y2, 1) = 0;
        img(x, y1, 2) = 255;
        img(x, y2, 2) = 255;
    }
    
    for (int y = r.y; y < r.y + r.height; y++) {
        int x1 = r.x;
        int x2 = r.x + r.width;
        
        img(x1, y, 0) = 0;
        img(x2, y, 0) = 0;
        img(x1, y, 1) = 0;
        img(x2, y, 1) = 0;
        img(x1, y, 2) = 255;
        img(x2, y, 2) = 255;
    }
}

inline void RectangleAll(CImg<unsigned char> img, vector<ss::Rect> rs) {
    
    CImg<unsigned char> t(img);
    
    for (int i = 0; i < rs.size(); i++) {
        Rectangle(t, rs[i]);
    }
    
    t.display();
}

#endif /* TextDetection_hpp */
