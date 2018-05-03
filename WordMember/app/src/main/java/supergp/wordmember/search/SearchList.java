package supergp.wordmember.search;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;

import supergp.wordmember.R;

public class SearchList extends AppCompatActivity{

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);
        ListView list = (ListView) findViewById(R.id.word_list);

        ArrayList<HashMap<String, String>> mylist = new ArrayList<HashMap<String, String>>();
        for(int i=0;i<30;i++) {
            HashMap<String, String> map = new HashMap<String, String>();
            map.put("ItemTitle", "This is Title.....");
            map.put("ItemText", "This is text.....");
            mylist.add(map);
        }

        SimpleAdapter mSchedule = new SimpleAdapter(this, mylist,
            R.layout.list_search,
            new String[] {"ItemTitle", "ItemText"},
            new int[] {R.id.item_word,R.id.item_exp});
        list.setAdapter(mSchedule);
    }
}
