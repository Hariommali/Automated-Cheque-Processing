            


import cv2

img = cv2.imread("sample.jpg")

# [rows, columns]

crop = img[ 706:1001,174:466]
cv2.imwrite('lft_fin.BMP', crop)



