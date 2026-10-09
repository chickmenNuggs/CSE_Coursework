package mauriciogranera.cse162_lab3.activityrecognition

import android.Manifest
import android.annotation.SuppressLint
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import mauriciogranera.cse162_lab3.activityrecognition.services.ActionDetectionService
import com.google.android.gms.location.DetectedActivity

class MainActivity : AppCompatActivity() {
    private lateinit var tvActivity: TextView
    private lateinit var tvConfidence: TextView
    private lateinit var btnStart: Button
    private lateinit var btnStop: Button
    private lateinit var activityDetectionService: ActionDetectionService

    companion object{
        const val PERMISSION_REQUEST_CODE = 100
        const val TAG = "MainActivity"
    }

    private val activityReceiver = object : BroadcastReceiver() {
        @SuppressLint("SetTextI18n")
        override fun onReceive(context: Context?, intent: Intent?) {
            val activities = intent?.getParcelableArrayListExtra<DetectedActivity>("activities")
            activities?.maxByOrNull { it.confidence }?.let { activity ->
                val activityName = getActivityName(activity.type)
                Log.d(TAG, "Detected Activity: $activityName, Confidence: ${activity.confidence}%")
                tvActivity.text = activityName
                tvConfidence.text = "Confidence: ${activity.confidence}%"
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        tvActivity = findViewById(R.id.tv_activity)
        tvConfidence = findViewById(R.id.tv_confidence)
        btnStart = findViewById(R.id.btn_start)
        btnStop = findViewById(R.id.btn_stop)

        activityDetectionService = ActionDetectionService(this)
        requestPermissions()
        btnStart.setOnClickListener {
            activityDetectionService.requestActivityUpdateHandler()
        }
        btnStop.setOnClickListener {
            activityDetectionService.removeActivityUpdateHandler()
        }
    }

    private fun requestPermissions() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            if (ActivityCompat.checkSelfPermission(
                    this,
                    Manifest.permission.ACTIVITY_RECOGNITION
                ) != PackageManager.PERMISSION_GRANTED
            ) {
                ActivityCompat.requestPermissions(
                    this,
                    arrayOf(Manifest.permission.ACTIVITY_RECOGNITION),
                    PERMISSION_REQUEST_CODE
                )
            }
        }
    }

    private fun getActivityName(type: Int): String {
        return when (type) {
            DetectedActivity.IN_VEHICLE -> "In Vehicle"
            DetectedActivity.ON_BICYCLE-> "On Bicycle"
            DetectedActivity.ON_FOOT -> "On Foot"
            DetectedActivity.RUNNING -> "Running"
            DetectedActivity.STILL -> "Still"
            DetectedActivity.TILTING -> "Tilting"
            DetectedActivity.UNKNOWN -> "Unknown"
            DetectedActivity.WALKING -> "Walking"
            else -> "Unknown"
        }
    }

    override fun onResume() {
        super.onResume()
        ContextCompat.registerReceiver(
            this,
            activityReceiver,
            IntentFilter("activity.intent"),
            ContextCompat.RECEIVER_NOT_EXPORTED
        )
    }

    override fun onPause() {
        super.onPause()
        unregisterReceiver(activityReceiver)
    }
}