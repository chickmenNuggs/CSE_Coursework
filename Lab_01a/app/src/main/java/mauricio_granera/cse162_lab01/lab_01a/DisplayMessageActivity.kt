package mauricio_granera.cse162_lab01.lab_01a

import android.os.Bundle
import android.view.ViewGroup
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
class DisplayMessageActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_display_message)
        val message = intent.getStringExtra(MainActivity.EXTRA_MESSAGE)
        val textView = TextView(this)
        textView.textSize = 40f
        textView.text = message
        val layout = findViewById<ViewGroup>(R.id.activity_display_message)
        layout.addView(textView)
    }
}