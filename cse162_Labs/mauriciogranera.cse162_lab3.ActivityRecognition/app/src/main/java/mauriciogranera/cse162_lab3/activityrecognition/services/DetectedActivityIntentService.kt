package mauriciogranera.cse162_lab3.activityrecognition.services

import android.app.IntentService
import android.content.Intent
import android.util.Log
import com.google.android.gms.location.ActivityRecognitionResult
import com.google.android.gms.location.DetectedActivity

class DetectedActivityIntentService: IntentService("DetectedActivityIntentService") {
    companion object{
        const val TAG = "DetectedActivityIS"
    }

    override fun onHandleIntent(intent: Intent?) {
        if (ActivityRecognitionResult.hasResult(intent)) {
            val result = ActivityRecognitionResult.extractResult(intent!!)
            val detectedActivities = result?.probableActivities

            detectedActivities?.forEach { activity ->
                Log.d(TAG, "Activity: ${getActivityName(activity.type)}" +
                    "Confidence: ${activity.confidence}")
            }

            val broadcastIntent = Intent("activity.intent")
            broadcastIntent.setPackage(packageName)
            broadcastIntent.putParcelableArrayListExtra(
                "activities",
                ArrayList(detectedActivities ?: emptyList())
            )
            sendBroadcast(broadcastIntent)
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

}