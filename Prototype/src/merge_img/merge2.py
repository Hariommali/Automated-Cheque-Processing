from PIL import Image

img1 = Image.open('shri.jpg')

img2 = Image.open('lal2.jpg')

image_new = Image.new('RGB', (img1.width+img2.width,img1.height))

image_new.paste(img1, (0,0))

image_new.paste(img2,(img1.width,0))

image_new.save('shrilal2.jpg')

img1 = Image.open('shrilal2.jpg')

img2 = Image.open('mali.jpg')

image_new = Image.new('RGB', (img1.width+img2.width,img1.height))

image_new.paste(img1, (0,0))

image_new.paste(img2,(img1.width,0))

image_new.save('shrilalmali2.jpg')
