import java.util.*;

public class Matrix {
  private int rows, cols;
  private float[] data;
  
  Matrix(int rows, int cols, float[] data) {
    this.rows = rows;
    this.cols = cols;
    
    if (data == null) {
      float info[] = new float[rows*cols];
      for (int i = 0; i < rows*cols; i++) {
        info[i] = 0;
      }
      this.data = info;
    } else {
      this.data = data;
    }  
  }
  
  public void randomize() {
    float range = 1 - (-1) + 1;
    for (int i = 0; i < this.rows * this.cols; i++) {
      this.data[i] = (float)(Math.random())*range + -1;
    }
  }
  
  //public static float sig(float x) {
  //  return 1 / (1 + (float)Math.exp(-x));
  //}
  
  //public static float dsig(float x) {
  //  return x / (1 - x);
  //}
  
  //public void map(String func) {
  //  for (int i = 0; i < this.rows*this.cols; i++) {
  //    if (func == "sig") {
  //      float elem = sig(this.data[i]);
  //      this.data[i] = elem;
  //    } else if (func == "dsig") {
  //      float elem = dsig(this.data[i]);
  //      this.data[i] = elem;
  //    }
  //  }
  //  System.out.println("MAP");
  //  return;
  //}
  
  //public static Matrix map(Matrix A, String func) {
  //  Matrix B = new Matrix(A.rows, A.cols, A.data);
  //  for (int i = 0; i < B.rows*B.cols; i++) {
  //    if (func == "sig") {
  //      B.data[i] = sig(B.data[i]);
  //    } else if (func == "dsig") {
  //      B.data[i] = dsig(B.data[i]);
  //    }
  //  }
  //  return B;
  //}
  
  public static native Matrix matrix_map(Matrix A, String func);
  public native void matrix_map(String func);
  
  public static native Matrix sclr_mult(Matrix A, float sclr);
  public static native Matrix sclr_add(Matrix A, float sclr);
  public native void sclr_mult(float sclr);
  public native void sclr_add(float sclr);
  
  public static native Matrix matrix_mult(Matrix A, Matrix B);
  public native void matrix_mult(Matrix B);
  
  public static native Matrix matrix_dot(Matrix A, Matrix B);
  public static native Matrix matrix_add(Matrix A, Matrix B);
  public static native Matrix matrix_sub(Matrix A, Matrix B);
  
  public native void matrix_add(Matrix B);
  public native void matrix_sub(Matrix B);
  
  public static native Matrix transpose(Matrix A);
  
  public static native Matrix fromArray(int rows, int cols, float[] data);
  public native float[] toArray();
  public float[] toArray_() {
    return this.data;
  }

  public native boolean is_equal(Matrix A);
  
  public native float get_element(int row, int col);
  public native void set_element(int row, int col, float element);
  public native void print();
  
  static { System.loadLibrary("matrix"); }
}
