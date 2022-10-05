import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.event.EventHandler;
import java.sql.*;

public class Forms extends Application {
    // Using Postgres SQL to use JDBC
    static String url = "jdbc:postgresql://localhost/postgres?user=postgres&password=root";
    static Connection con = null;
    static Statement st = null;

    public static void main(String[] args) throws SQLException{
        try{
            con = DriverManager.getConnection(url);
            st = con.createStatement();
            // Creating a table in SQL
            String sql = "CREATE TABLE IF NOT EXISTS FORM(name varchar(30),"+
                    "e_mail varchar(50)," +
                    "mobile numeric(10));";
            ResultSet r = st.executeQuery(sql);
            con.close(); //always remember to close the connection
        }catch (SQLException e){
            e.printStackTrace();
        }
        launch(args);
    }

    @Override
    // JavaFx
    public void start(Stage primaryStage) {
        // Software widget declarations
        GridPane gridPane = new GridPane();
        Text t1 = new Text("Name: ");
        Text t2 = new Text("E-Mail ID: ");
        Text t3 = new Text("Mobile Number: ");
        TextField tf1 = new TextField();
        TextField tf2 = new TextField();
        TextField tf3 = new TextField();
        Button b = new Button("Submit");

        //Positioning the widgets
        gridPane.add(t1,0,1);
        gridPane.add(tf1,2,1);
        gridPane.add(t2,0,3);
        gridPane.add(tf2,2,3);
        gridPane.add(t3,0,5);
        gridPane.add(tf3,2,5);
        gridPane.add(b,2,10);

        gridPane.setAlignment(Pos.CENTER);

        //Whats should happen when submit button is clicked.
        EventHandler<ActionEvent> eventHandler = new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                String name = tf1.getText();
                String email = tf2.getText();
                Long mobile = Long.parseLong(tf3.getText());
                String insert = "'" + name + "'" + "," + "'" + email + "'" + "," + mobile;

                try{
                    //Inserting values in table created above
                    String query1 = "INSERT INTO FORM VALUES(" + insert + ")";
                    ResultSet r1 = st.executeQuery(query1);
                    con.close();
                }catch (SQLException e){
                    e.printStackTrace();
                }
                try{
                    //Viewing all the values in table
                    String query2 = "SELECT * FROM FORM";
                    ResultSet r2 = st.executeQuery(query2);
                    while (r2.next()){ //next is used to iterate between table values
                        String n = r2.getString("name");
                        String e = r2.getString("e_mail");
                        String m = r2.getString("mobile");
                        System.out.println(n + ", " + e + ", " + m);
                    }
                }catch (SQLException e){
                    e.printStackTrace();
                }
            }
        };
        b.setOnAction(eventHandler);
        Scene scene = new Scene(gridPane,800,500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Forms");
        primaryStage.show();
    }
}