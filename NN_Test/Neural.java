public class Neural {
  private int num_input;
  private int num_hidden;
  private int num_output;
  private float learning_rate;
  
  private Matrix weights_IH;
  private Matrix weights_HO;
  private Matrix bias_H;
  private Matrix bias_O;
  
  Neural(int num_input, int num_hidden, int num_output) {
    this.num_input = num_input;
    this.num_hidden = num_hidden;
    this.num_output = num_output;
    
    this.weights_IH = new Matrix(num_hidden, num_input, null);
    this.weights_IH.randomize();
    this.weights_HO = new Matrix(num_output, num_hidden, null);
    this.weights_HO.randomize();
    
    this.bias_H = new Matrix(num_hidden, 1, null);
    this.bias_H.randomize();
    this.bias_O = new Matrix(num_output, 1, null);
    this.bias_O.randomize();
    
    this.learning_rate = 0.1;
  }
  
  public native Matrix feedforward(Matrix input);
  public native void train(Matrix input, Matrix answer);
  
  static { System.loadLibrary("neural"); }
}
