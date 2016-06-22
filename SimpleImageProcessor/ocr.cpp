#include "ocr.h"
#include<QColor>
#include<iostream>
using namespace std;
QVector<QImage> OCR::doOCR(QImage &image){
    QVector<QImage> result;
    QVector<pair<int, int> > lines = horizontalProjection(image);
    for(int i = 0; i < lines.size(); i++){
        pair<int, int> line = lines[i];
        int begin = line.first;
        int end = line.second;
        QVector<QImage> characters = verticalProjection(image, begin, end);
        for(int i = 0; i < characters.size(); i++){
            result.push_back(characters[i]);
        }
    }

    return result;
}

QVector<pair<int,int> > OCR::horizontalProjection(QImage& image){
    cout << "horizontalProjection " << image.height()<< endl;
    QVector<int> vector;
    for(int i = 0; i < image.height(); i++){
        int cnt = 0;
        for(int j = 0; j < image.width(); j++){
            QColor c = QColor::fromRgb(image.pixel(j, i));
            if(c == Qt::black){
                cnt++;
            }
        }
        vector.push_back(cnt);
    }
    int begin=-1, end =-1;
    for(int i = 0; i < vector.size(); i++){
        if(vector[i] != 0){
            begin = i;
            end = i;break;

        }
    }
    cout << begin << " " << vector.size() << endl;
    QVector<pair<int,int> > pairs;
    for(int i = begin; i < vector.size(); i++){
        if(vector[i] != 0){
            if(begin <= end){
                end++;
            }
        } else {
            if(begin < end) {pairs.push_back(make_pair(begin, end -1));
            begin = end;
            }
            begin++;
            end++;
        }
    }
    return pairs;
}

QVector<QImage> OCR::verticalProjection(QImage& image, int begin, int end){
        cout << "vertical projection " << begin << " " << end  << " " << image.height()<< endl;
        QVector<QImage> characters;
        QVector<int> counts;
        for(int j = 0; j < image.width(); j++){
             int cnt = 0;
             for(int i = begin; i <= end; i++){
                 QColor c = QColor::fromRgb(image.pixel(j, i));
                 if(c == Qt::black){
                     cnt++;
                 }
             }
             counts.push_back(cnt);
        }

        for(int i = 0; i < counts.size(); i++){
            if(counts[i]!=0){
                int pos = i;
                for(int j = i+1; j < counts.size(); j++){
                    if(counts[j] == 0){
                        pos = j-1;
                        break;
                    }
                }

                QImage subImage = image.copy(i,begin,pos - i + 1,end - begin);
                characters.push_back(subImage);
                i = pos+1;
            }
        }
    return characters;
}
