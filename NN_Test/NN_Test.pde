void setup() {
  //System.out.println(System.getProperty("java.library.path"));
  Neural N = new Neural(2, 1, 1);
  float[] data = {1, 0};
  Matrix input = new Matrix(2, 1, data);
  input.print();
  //Matrix B = new Matrix(2, 1, {0, 0});
  Matrix guess = N.feedforward(input);
  guess.print();
  
}

void draw() {
  
}
