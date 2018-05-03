package supergp.wordmember.notebook;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;

import supergp.wordmember.R;

public class NoteList extends AppCompatActivity{

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_shell);
        ListView list = (ListView) findViewById(R.id.note_list);

        ArrayList<HashMap<String, String>> mylist = new ArrayList<HashMap<String, String>>();
        for(int i=0;i<30;i++) {
            HashMap<String, String> map = new HashMap<String, String>();
            map.put("ItemTitle", "This is Title.....");
            mylist.add(map);
        }

        SimpleAdapter mSchedule = new SimpleAdapter(this, mylist,
                R.layout.list_note,
                new String[] {"ItemTitle"},
                new int[] {R.id.note_name});
        list.setAdapter(mSchedule);
    }
}
