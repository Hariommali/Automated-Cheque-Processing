import cv2


# read the image

img = cv2.imread("sample.jpg")

print(type(img))


# Check the shape of the input image

print("Shape of the image", img.shape)
