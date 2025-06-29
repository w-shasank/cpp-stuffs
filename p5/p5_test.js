let x = 0;

function setup() {
  createCanvas(1000, 1000);
}

function draw() {
  background(0);
  fill(255, 0, 0);
  ellipse(x, 50, 50, 50);
  ellipse(x+100, 200, 50, 50);

  x += 2;
  if (x > width) {
    x = 0;
  }
}
