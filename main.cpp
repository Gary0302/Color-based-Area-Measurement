#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

void processImage(const string& imagePath, const Scalar& lowerBound, const Scalar& upperBound, const string& outputDir);

int main() {
    string datasetPath = "./dataset";  // 圖片資料夾路徑
    string outputPath = "./output";   // 結果輸出路徑

    // 確保輸出目錄存在
    if (!fs::exists(outputPath)) {
        fs::create_directories(outputPath);
    }

    // 檢查資料夾是否存在
    if (!fs::exists(datasetPath) || !fs::is_directory(datasetPath)) {
        cerr << "資料夾不存在或無效: " << datasetPath << endl;
        return -1;
    }

    // 輸入目標顏色和相似度閾值
    int targetR, targetG, targetB, threshold;
    cout << "請輸入目標顏色 (R G B): ";
    cin >> targetR >> targetG >> targetB;
    cout << "請輸入相似度閾值 (建議10-50): ";
    cin >> threshold;

    // 計算目標顏色範圍
    Vec3b targetColorBGR(targetB, targetG, targetR);
    Mat targetHSV;
    Mat bgrMat(1, 1, CV_8UC3, targetColorBGR);
    cvtColor(bgrMat, targetHSV, COLOR_BGR2HSV);
    Vec3b targetColorHSV = targetHSV.at<Vec3b>(0, 0);

    Scalar lowerBound(max(0, targetColorHSV[0] - threshold),
                      max(0, targetColorHSV[1] - threshold),
                      max(0, targetColorHSV[2] - threshold));
    Scalar upperBound(min(179, targetColorHSV[0] + threshold),
                      min(255, targetColorHSV[1] + threshold),
                      min(255, targetColorHSV[2] + threshold));

    // 遍歷資料夾中的所有圖像
    for (const auto& entry : fs::directory_iterator(datasetPath)) {
        if (entry.is_regular_file()) {
            string extension = entry.path().extension().string();
            if (extension == ".jpg" || extension == ".webp") {
                string imagePath = entry.path().string();
                cout << "處理圖像: " << imagePath << endl;
                processImage(imagePath, lowerBound, upperBound, outputPath);
            }
        }
    }

    cout << "所有圖像處理完成！結果儲存於: " << outputPath << endl;
    return 0;
}

void processImage(const string& imagePath, const Scalar& lowerBound, const Scalar& upperBound, const string& outputDir) {
    // 載入圖像
    Mat image = imread(imagePath);

    if (image.empty()) {
        cerr << "無法載入圖像: " << imagePath << endl;
        return;
    }

    // 轉換為 HSV 色彩空間
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    // 產生遮罩
    Mat mask;
    inRange(hsvImage, lowerBound, upperBound, mask);

    // 計算面積
    int area = countNonZero(mask);
    cout << "目標顏色的區域面積: " << area << " 像素" << endl;

    // 繪製結果圖像
    Mat result;
    bitwise_and(image, image, result, mask);

    // 儲存結果圖像
    string fileName = fs::path(imagePath).filename().string();
    string outputPath = outputDir + "/output_" + fileName;
    imwrite(outputPath, result);
    cout << "結果已儲存至: " << outputPath << endl;
}
