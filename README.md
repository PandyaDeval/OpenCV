# OpenCV
Trying out basic OpenCV functions including reading, converting and transforming images to obtain the skeleton of an imahge which could be further processesed using various algorithms.
Source: OpenCV documentation https://docs.opencv.org/2.4/opencv_tutorials.pdf

# Reading/ Writing an image
An image can be represented as a matrix representing its pixel values.
Mat img = imread("image.jpg", 1); //Creates an object named img of class Mat and loads image.jpg 
Mat is basically a class with two data parts: the matrix header (containing information such as the size of the matrix, the method used for storing, at which address is the matrix stored, and so on) and a pointer to the matrix containing the pixel values (taking any dimensionality depending on the method chosen for storing).
namedWindow("MyWindow", WINDOW_AUTOSIZE); //Creates a window named "MyWindow" 
imshow("MyWindow", img); //Loads img in the window "MyWindow"

# Color Conversion
OpenCV provides optimized color conversion functions.
Converts RGB image into Gray
cvtColor(src, dst, CV_RGB2GRAY); 

# Blend two images
beta = ( 1.0 - alpha );
addWeighted( src1, alpha, src2, beta, 0.0, dst);
beta = ( 1.0 - alpha );
addWeighted( src1, alpha, src2, beta, 0.0, dst);

# Changing the Contrast/Brightness of an image
This kind of transformation is obtained by transformation in the pixel value of the image.Two commonly used point processes are multiplication and addition with a constant:
g(x) = alpha*f(x)+ beta
aplha>0 and beta is the parameter controlling the contrast/ brightness of an image

f(x) can be expressed as a 2-D matrix in case of real images.
for( int y = 0; y < image.rows; y++ )
   { for( int x = 0; x < image.cols; x++ )
        { for( int c = 0; c < 3; c++ )
             { new_image.at<Vec3b>(y,x)[c] =
                         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta ); }
   }
   }
for loops can be used to obtain transformation in pixel values of an image.
image.convertTo(new_image, -1, alpha, beta); //Function which can simply be used instead of for loops.
  
# Smoothing Images
Smoothing of an image refers to blurring the image. To perform a smoothing operation we will apply a filter to our image. The most common type of filters are linear, in which an output pixel’s value (i.e. g(i,j)) is determined as a weighted sum of input pixel values (i.e. f(i+k,j+l)) :
g(i,j) = sum(f(i+k, j+l) h(k,l))
h(k,l) is called the kernel, which is nothing more than the coefficients of the filter.
Types of filter: 
1. Noralised Block Filter
2. Gaussian Filter
3. Bilateral Filter
4. Median Filter
GaussianBlur(gray, grayblur,Size(15, 15),0);// size (15, 15) represents the size of the kernel

# Eroding and Dilating an image
Dilation makes the image bigger and eroson makes the image smaller. Both images beign subtracted using addWeighted function gives the skeleton of the images. Changing the value of parameters used in funtion reduces cracks in the skeleton obtained. In case of real image the possibility of cracks are higher.
Mat element;
element = Mat();
erode(dst, erode_img, element);





