
//Class containing 'main' method
public class App {
 
    public static void main(String args[]){
 
        //Creating A1, A2, A3 & A4 
        Matrix matrices[] = {new Matrix(30,1),
                new Matrix(1,40),
                new Matrix(40,10),
                new Matrix(10,25)};
 
        MatrixChain matrixChain = new MatrixChain(matrices);
        int multiplications = matrixChain.solve();
 
        //Printing 2D array (memoize table)
        for(int i=0; i<matrices.length; i++){
 
            for(int j=0; j<matrices.length; j++){
 
                System.out.print(matrixChain.matrixMulCount[i][j]+ "\t");
            }
 
            System.out.println();
 
        }
 
        System.out.println("Minimum multiplications required: "+multiplications);
    }
}