# YOLOv8 Visual Inspection

The current prototype includes a webcam-based visual inspection pipeline using a YOLOv8-based AI model.

## Pipeline

```text
Webcam
   ↓
Video Frame
   ↓
YOLOv8 Model
   ↓
Object / Defect Detection
   ↓
Detection Result
```

## Current Status

The YOLOv8 module is under prototype development.

Model weights, dataset configuration, training scripts and inference implementation will be added as they are finalized.

## Planned Structure

```text
yolov8/
├── README.md
├── training/
├── inference/
├── dataset/
└── weights/
```

Large model weights and datasets should not be committed directly to the repository unless an appropriate large-file storage solution is configured.
\