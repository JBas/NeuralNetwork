Neural N;

class TO {
  float[] inputs;
  float[] outputs;
  
  TO(float[] input, float[] output) {
    inputs = input;
    outputs = output;
  }
}

TO[] training_data = {
  new TO( new float[] {0, 0}, new float[] {0} ),
  new TO( new float[] {0, 1}, new float[] {1} ),
  new TO( new float[] {1, 0}, new float[] {1} ),
  new TO( new float[] {1, 1}, new float[] {0} )
};

float parab(float x) {
  return (x - 0.5)*(x - 0.5);
}

void setup() {
  //System.out.println(System.getProperty("java.library.path"));
  size(400, 400);
  N = new Neural(2, 2, 1);
}

void draw() {
  background(0);
  
  for (int i = 0; i < 50000; i++) {
    int index = (int)random(0, 4);
    TO data = training_data[index];
    N.train(new Matrix(2, 1, data.inputs), new Matrix(1, 1, data.outputs));
  }
  
  int resolution = 10;
  int cols = width / resolution;
  int rows = height / resolution;
  
  for (int i = 0 ; i < cols; i++) {
    for (int j = 0 ; j < rows; j++) {
      float x1 = (float)i / (float)cols;
      float x2 = (float)j / (float)rows;
      float[] inputs = {x1, x2};
      
      Matrix guess = N.feedforward(new Matrix(2, 1, inputs));
      float[] y = guess.toArray();
      fill(y[0] * 255);
      rect(i*resolution, j*resolution, resolution, resolution);
    }
  }
}
