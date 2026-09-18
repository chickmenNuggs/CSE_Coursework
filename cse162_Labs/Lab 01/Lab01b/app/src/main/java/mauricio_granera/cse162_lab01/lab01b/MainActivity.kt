package mauricio_granera.cse162_lab01.lab01b

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity(),
    HeadlineFragment.OnHeadLineSelectedListener {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    override fun onArticleSelected(position: Int){
        val newsFragment = supportFragmentManager
            .findFragmentById(R.id.news_fragment) as? NewsFragment
        newsFragment?.updateArticleView(position)
    }

}