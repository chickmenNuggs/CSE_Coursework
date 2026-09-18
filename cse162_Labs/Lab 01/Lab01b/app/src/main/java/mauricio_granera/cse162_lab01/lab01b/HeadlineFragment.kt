package mauricio_granera.cse162_lab01.lab01b

import android.content.Context
import android.os.Bundle
import android.view.View
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.constraintlayout.motion.widget.KeyPosition
import androidx.fragment.app.ListFragment

class HeadlineFragment : ListFragment(){

    interface OnHeadLineSelectedListener{
        fun onArticleSelected(position: Int)
    }

    private var mCallback: OnHeadLineSelectedListener? = null

    override fun onAttach(context: Context) {
        super.onAttach(context)
        try {
            mCallback = context as OnHeadLineSelectedListener
        } catch (e: ClassCastException){
            throw ClassCastException("$context must implement OnHeadlineListener")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val layout = android.R.layout.simple_list_item_activated_1
        listAdapter = ArrayAdapter(
            requireActivity(),
            layout,
            Ipsum.headlines
        )
    }

    override fun onStart() {
        super.onStart()
        if (parentFragmentManager.findFragmentById(R.id.news) != null) {
            listView.choiceMode = ListView.CHOICE_MODE_SINGLE
        }
    }

    override fun onListItemClick(l: ListView, v: View, position: Int, id: Long) {
        mCallback?.onArticleSelected(position)
        listView.setItemChecked(position, true)
    }

    override fun onDetach() {
        super.onDetach()
        mCallback = null
    }
}

