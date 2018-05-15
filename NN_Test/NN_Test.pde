void setup() {
  //System.out.println(System.getProperty("java.library.path"));

  Matrix A = new Matrix(3, 3, null);
  A.randomize();
  //print(A.get_element(0, 0));
  //print("\n\n");
  
  //A.set_element(0, 0, 1);
  //print(A.get_element(0, 0));
  //print("\n\n");
  A.print();
  
  Matrix B = Matrix.transpose(A);
  B.print();
  A.matrix_sub(B);
  A.print();
}

void draw() {
  
}
