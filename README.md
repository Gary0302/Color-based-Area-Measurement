# Color-Based Area Measurement

## 專案簡介 (Project Introduction)

此專案使用 OpenCV 開發了一個 C++ 程式，能夠根據顏色來測量圖像中特定區域的面積。用戶可以指定目標顏色 (RGB 格式) 和相似度閾值，程式會繪製匹配區域並計算像素面積。所有處理結果會輸出至專案根目錄下的 `output` 資料夾。

*English*: This project is a C++ program developed with OpenCV to measure specific regions in an image based on their color. Users can specify the target color (in RGB format) and a similarity threshold. The program highlights the matching regions and calculates their pixel area. All results are saved to the `output` folder in the project root directory.

## 功能 (Features)

### 輸入與處理 (Input and Processing)
1. 從 `dataset` 資料夾中讀取所有 `.jpg` 和 `.webp` 格式的圖像
2. 支持用戶自定義目標顏色及相似度閾值
3. 生成遮罩，顯示與目標顏色匹配的區域

*English*:
1. Reads all `.jpg` and `.webp` images from the `dataset` folder
2. Allows users to define target color and similarity threshold
3. Generates masks to display regions matching the target color

### 輸出 (Output)
- 在 `output` 資料夾中保存處理後的圖像
- 在終端中輸出目標區域的像素面積

*English*:
- Save processed images in the `output` folder
- Display pixel area of target regions in the terminal

## 專案結構 (Project Structure)

```
.
├── dataset/        # 圖像資料夾 (Images folder)
│   ├── sample1.jpg
│   ├── sample2.webp
│   └── ...
├── output/         # 結果輸出資料夾 (Generated output folder)
├── build/          # 編譯輸出資料夾 (Build folder)
├── CMakeLists.txt  # CMake 配置檔 (CMake configuration file)
└── main.cpp        # 主程式碼檔案 (Main program file)
```

## 運行步驟 (How to Run)

### 前置需求 (Prerequisites)
- C++ 編譯器 (如 GCC)
- OpenCV 庫
- CMake 工具

*English*:
- C++ compiler (e.g., GCC)
- OpenCV library
- CMake tool

### 安裝與編譯 (Installation and Build)

1. 克隆倉庫
```bash
git clone <repository-url>
cd <repository-folder>
```

2. 編譯專案
```bash
mkdir build
cd build
cmake ..
make
```

3. 執行程式
```bash
cd ..
build/color_measure
```

### 參數輸入 (Parameter Input)

- **目標顏色 (Target Color)**: 輸入 RGB 顏色值，例如：`255 0 0`（紅色）
- **相似度閾值 (Similarity Threshold)**: 設定匹配範圍，例如：`30`

*English*:
- **Target Color**: Input RGB color value, e.g., `255 0 0` (red)
- **Similarity Threshold**: Set matching range, e.g., `30`

## 結果驗證 (Result Verification)
- 處理後的圖像將儲存在 `output` 資料夾
- 像素面積將顯示在終端中

*English*:
- Processed images will be saved in the `output` folder
- Pixel area will be displayed in the terminal

## 參考資料 (References)
- [OpenCV Documentation](https://docs.opencv.org/)
- [CMake Documentation](https://cmake.org/documentation/)

## 授權 (License)
MIT license