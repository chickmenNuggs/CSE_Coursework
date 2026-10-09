package mauriciogranera.cse162_lab3.activityrecognition.services

import android.app.PendingIntent
import android.content.Context
import android.content.Intent
import android.os.Build
import android.util.Log
import mauriciogranera.cse162_lab3.activityrecognition.utils.Constant
import com.google.android.gms.location.ActivityRecognitionClient
import com.google.android.gms.location.ActivityRecognition

class ActionDetectionService (private val context: Context){

    companion object{
        const val TAG = "ActionDetectionService"
    }


    private val activityRecognitionClient: ActivityRecognitionClient =
        ActivityRecognition.getClient(context)

    private val pendingIntent: PendingIntent by lazy {
        val intent = Intent(context, DetectedActivityIntentService::class.java)
        val flags = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            PendingIntent.FLAG_UPDATE_CURRENT or PendingIntent.FLAG_MUTABLE
        } else {
            PendingIntent.FLAG_UPDATE_CURRENT
        }
        PendingIntent.getService(
            context,
            0,
            intent,
            flags
        )
    }

    fun requestActivityUpdateHandler() {
        activityRecognitionClient.requestActivityUpdates(
            Constant.DETECTION_INTERVAL_IN_MILLISECONDS,
            pendingIntent
        ).addOnSuccessListener {
            Log.d(TAG, "Activity updates requested")
        }.addOnFailureListener {
            Log.e(TAG, "Failed to request activity updates: ${it.message}")
        }
    }

    fun removeActivityUpdateHandler() {
        activityRecognitionClient.removeActivityUpdates(pendingIntent)
            .addOnSuccessListener {
                Log.d(TAG, "Activity updates removed")
            }.addOnFailureListener {
                Log.d(TAG, "Failed to remove activity updates: ${it.message}")
            }
    }

}