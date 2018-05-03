package supergp.wordmember.plan;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

import java.util.ArrayList;
import java.util.List;

import supergp.wordmember.R;

public class TodayPlan extends AppCompatActivity{
    private List<String> setList = new ArrayList<String>();
    private ArrayAdapter<String> setAdapter;
    private Spinner setSpinner;
    private Button newLearn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_today);

        setList.add("中考");
        setList.add("高考");
        setList.add("大学四级");
        setList.add("大学六级");
        setList.add("雅思");
        setList.add("托福");
        setList.add("GRE");

        setSpinner = (Spinner)findViewById(R.id.spinner_set);
        setAdapter = new ArrayAdapter<>(this,android.R.layout.simple_spinner_item, setList);
        setAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        setSpinner.setAdapter(setAdapter);
        setSpinner.setOnItemSelectedListener(new Spinner.OnItemSelectedListener(){
            public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {

            }
            public void onNothingSelected(AdapterView<?> arg0) {

            }
        });

        newLearn = (Button)findViewById(R.id.new_learning);
        newLearn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(TodayPlan.this,WordLearn.class);
                startActivity(intent);
            }
        });
    }
}
