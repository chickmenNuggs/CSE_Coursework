package mauricio_granera.cse162_lab01.lab01b

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.fragment.app.Fragment

class NewsFragment : Fragment() {

    companion object{
        const val ARG_POSITION = "position"
    }

    private var mCurrentPosition = -1

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        if (savedInstanceState != null){
            mCurrentPosition = savedInstanceState.getInt(ARG_POSITION)
        }
        return inflater.inflate(R.layout.fragment_news, container, false)
    }

    override fun onStart() {
        super.onStart()
        val args = arguments
        if (args != null) {
            updateArticleView(args.getInt(ARG_POSITION))
        } else if (mCurrentPosition >= 0){
            updateArticleView(mCurrentPosition)
        }
    }

    fun updateArticleView(position: Int){
        val article = requireView().findViewById<TextView>(R.id.news)
        article.text = Ipsum.articles[position]
        article.visibility = View.VISIBLE
        mCurrentPosition = position
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putInt(ARG_POSITION, mCurrentPosition)
    }
}