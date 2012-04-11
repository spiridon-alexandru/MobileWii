package udppoc.lenamespace;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.SocketException;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class UdpAndroidPOCActivity extends Activity  implements SensorEventListener {
	private DatagramSocket s;
	private int messageNumber = 0;
	
	static int server_port = 12345;
	
	// accelerometer stuff
	private float mLastX, mLastY, mLastZ;
	private boolean mInitialized;

	private SensorManager mSensorManager;
	private Sensor mAccelerometer;
    
	/** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        mInitialized = false;
        mSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_GAME);
        
        final Button button = (Button) findViewById(R.id.button1);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                // Send a test message to the sever on button click
            	messageNumber++;
            	
                String messageStr="Message number " + String.valueOf(messageNumber);
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
        });
    }
    
    protected void onResume() 
    {
    	super.onResume();
    	mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
	}
    
	protected void onPause() 
	{
		super.onPause();
		mSensorManager.unregisterListener(this);
	}
	
	@Override
	public void onAccuracyChanged(Sensor sensor, int accuracy) 
	{
		// can be safely ignored for now
	}
	
	@Override
	public void onSensorChanged(SensorEvent event) 
	{
		float x = event.values[0];
		float y = event.values[1];
		float z = event.values[2];
		
		messageNumber++;
		// we only take into consideration the y axis - the phone will handle
		// the landscape horizontal tilt
        String messageStr=String.valueOf(y);
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