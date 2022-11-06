            


import cv2

img = cv2.imread("upload_doc/sample.jpg")

# [rows, columns]

crop = img[ 706:1001,1550:1847]
cv2.imwrite('rgt_fin.BMP', crop)



