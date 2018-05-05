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
    for (int i = 0; i < this.rows * this.cols; i++) {
      this.data[i] = (float)Math.random();
    }
  }
  
  public native Matrix transpose(Matrix A);
  public native boolean is_equal(Matrix A);
  public native float get_element(int row, int col);
  public native void set_element(int row, int col, float element);
  public native void print();
  
  static { System.loadLibrary("Matrix_lib"); }
}
