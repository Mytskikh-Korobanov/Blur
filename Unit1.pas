Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure On_Scroll(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit1.Form1.resources}
    pictureBox1: PictureBox;
    button1: Button;
    pictureBox2: PictureBox;
    pictureBox3: PictureBox;
    label1: &Label;
    label2: &Label;
    label3: &Label;
    trackBar1: TrackBar;
    label4: &Label;
    openFileDialog1: OpenFileDialog;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation

var
  b1, b2, b3: BitMap;
  sigma: real;

// процедура размытия по Гауссу
procedure blur(sigma: real; var data: BitMap);
var
  wind: array of real;
  buf1, buf2: array of longint;
  size, med, i, j, k, m: integer;
  sum, pix_red: real;
  pix_r, red: longint;
begin
  setlength(buf1, data.width);
  // создание окна фильтра
  size := 3 * round(sigma);
  setlength(wind, 2 * size + 1);
  med := size;
  // задание окну фильтра значений
  for i := 0 to 2*size do
  begin
    if i = med then wind[i] := 1
      else
        wind[i] := exp(-1*sqr(med-i)/(2*sqr(sigma)));
  end;
  // первый проход - горизонтальное размытие
  for i := 0 to data.Height-1 do
  begin
    for j := 0 to data.Width-1 do
    begin
      sum := 0;
      pix_red := 0;
      for k := -size to size do
      begin
        m := j + k;
        if (m >= 0) and (m <= data.Width-1)
          then
          begin
            red := data.GetPixel(m, i).R;
            pix_red := pix_red + red*wind[k+size];
            sum := sum + wind[k+size];
          end
      end;
      pix_red := pix_red / sum;
      pix_r := round(pix_red);
      buf1[j] := pix_r;
    end;
    for j := 0 to data.Width-1 do
      data.SetPixel(j,i,Color.FromArgb(buf1[j], 0, 0));
  end;
  setlength(buf2, data.height);
   // второй проход - вертикальное размытие
  for i := 0 to data.Width-1 do
  begin
    for j := 0 to data.Height-1 do
    begin
      sum := 0;
      pix_red := 0;
      for k := -size to size do
      begin
        m := j + k;
        if (m >= 0) and (m <= data.Height-1)
          then
          begin
            red := data.GetPixel(i, m).R;
            pix_red := pix_red + red*wind[k+size];
            sum := sum + wind[k+size];
          end
      end;
      pix_red := pix_red / sum;
      pix_r := round(pix_red);
      buf2[j] := pix_r;
    end;
    for j := 0 to data.Height-1 do
      data.SetPixel(i,j,Color.FromArgb(buf2[j], 0, 0));
  end;
 
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var 
  i, j: integer;
  pix: color;
  r: byte;
begin
  openFileDialog1.ShowDialog;
  pictureBox1.ImageLocation := openFileDialog1.Filename;
  b1 := new BitMap(openFileDialog1.Filename);
  b2 := new BitMap(openFileDialog1.Filename);
  b3 := new BitMap(openFileDialog1.Filename);
  for i := 0 to b1.Height-1 do
    for j := 0 to b1.width-1 do
    begin
      pix := b1.GetPixel(j,i);
      r := pix.R;
      pix := color.FromArgb(r,0,0);
      b2.SetPixel(j, i, pix);
    end;
  pictureBox2.Image := b2;
  for i := 0 to b2.Height-1 do
    for j := 0 to b2.width-1 do
      b3.SetPixel(j, i, b2.GetPixel(j,i));
  sigma := trackBar1.value;
  blur(sigma,b3);
  pictureBox3.Image := b3;
end;

procedure Form1.On_Scroll(sender: Object; e: EventArgs);
var
  i, j: integer;
begin
  for i := 0 to b2.Height-1 do
    for j := 0 to b2.width-1 do
      b3.SetPixel(j, i, b2.GetPixel(j,i));
  sigma := trackBar1.value;
  blur(sigma,b3);
  pictureBox3.Image := b3;
end;

end.