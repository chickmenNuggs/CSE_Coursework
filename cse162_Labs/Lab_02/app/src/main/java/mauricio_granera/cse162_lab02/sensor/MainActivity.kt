package mauricio_granera.cse162_lab02.sensor

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import android.hardware.SensorManager
import android.widget.EditText
import java.text.DecimalFormat


class MainActivity : AppCompatActivity(), SensorEventListener {

    public lateinit var sensorManager: SensorManager
    private var gravity: Sensor? = null;
    private var magnetic: Sensor? = null;
// μ for coppy and pasty boi

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        gravity = sensorManager.getDefaultSensor(Sensor.TYPE_GRAVITY)
        magnetic = sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD)

    }

    override fun onResume() {
        super.onResume()
        sensorManager.registerListener(this,gravity, SensorManager.SENSOR_DELAY_NORMAL)
        sensorManager.registerListener(this,magnetic, SensorManager.SENSOR_DELAY_NORMAL)
    }

    override fun onPause() {
        super.onPause()
        sensorManager.unregisterListener(this)
    }
    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {
        // Not required for basic logging, but required by interface
    }

    override fun onSensorChanged(sensorEvent: SensorEvent){
        val f = DecimalFormat("0.00")

        if (sensorEvent.sensor.type == Sensor.TYPE_GRAVITY){
            val uXGval = sensorEvent.values[0];
            val uYGval = sensorEvent.values[1];
            val uZGval = sensorEvent.values[2];

            val gnx = findViewById<EditText>(R.id.uiGravX)
            val gny = findViewById<EditText>(R.id.uiGravY)
            val gnz = findViewById<EditText>(R.id.uiGravZ)
            gnx.setText(f.format(uXGval) + " m/s\u00B2")
            gny.setText(f.format(uYGval) + " m/s\u00B2")
            gnz.setText(f.format(uZGval) + " m/s\u00B2")
        }
        if (sensorEvent.sensor.type == Sensor.TYPE_MAGNETIC_FIELD){
            val uXMval = sensorEvent.values[0];
            val uYMval = sensorEvent.values[1];
            val uZMval = sensorEvent.values[2];

            val mnx = findViewById<EditText>(R.id.uiMagX)
            val mny = findViewById<EditText>(R.id.uiMagY)
            val mnz = findViewById<EditText>(R.id.uiMagZ)
            mnx.setText(f.format(uXMval) + " μT")
            mny.setText(f.format(uYMval) + " μT")
            mnz.setText(f.format(uZMval) + " μT")
        }

    }
}
