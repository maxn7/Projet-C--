

echo 2 1 1 1 | ../main > ../plot/CAechelon.dat;
echo 2 2 1 1 | ../main > ../plot/CAporte.dat;
echo 2 3 1 1 | ../main > ../plot/CAcarre.dat;
echo 2 4 1 1 | ../main > ../plot/CAtriangle.dat;

echo 3 1 1 1 1 | ../main > ../plot/CBechelon.dat;
echo 3 2 1 1 1 | ../main > ../plot/CBporte.dat;
echo 3 3 1 1 1 | ../main > ../plot/CBcarre.dat;
echo 3 4 1 1 1 | ../main > ../plot/CBtriangle.dat;

echo 4 6 | ../main > ../plot/exemple2.dat;

echo 5 1 1 1 1 | ../main > ../plot/CCechelon.dat;
echo 5 2 1 1 1 | ../main > ../plot/CCporte.dat;
echo 5 3 1 1 1 | ../main > ../plot/CCcarre.dat;
echo 5 4 1 1 1 | ../main > ../plot/CCtriangle.dat;

echo 6 1 1 1 1 | ../main > ../plot/CDechelon.dat;
echo 6 2 1 1 1 | ../main > ../plot/CDporte.dat;
echo 6 3 1 1 1 | ../main > ../plot/CDcarre.dat;
echo 6 4 1 1 1 | ../main > ../plot/CDtriangle.dat;

gnuplot aTrace;
rm images/concat.pdf
pdftk images/*.pdf cat output images/concat.pdf;

