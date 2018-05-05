void setup() {
  //System.out.println(System.getProperty("java.library.path"));

  Matrix A = new Matrix(3, 3, null);
  A.randomize();
  print(A.get_element(0, 0));
  print("\n\n");
  A.print();
}

void draw() {
  
}
