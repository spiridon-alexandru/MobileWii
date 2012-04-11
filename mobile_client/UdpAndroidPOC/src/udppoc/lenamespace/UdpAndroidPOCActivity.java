package udppoc.lenamespace;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.SocketException;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class UdpAndroidPOCActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        String messageStr="Hello Android!";
        int server_port = 12345;
        DatagramSocket s;
		try {
			s = new DatagramSocket();
			InetAddress local = InetAddress.getByName("192.168.1.41");
	        int msg_length=messageStr.length();
	        byte[] message = messageStr.getBytes();
	        DatagramPacket p = new DatagramPacket(message, msg_length,local,server_port);
	        s.send(p);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
}