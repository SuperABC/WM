package supergp.wordmember;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;

import supergp.wordmember.notebook.NoteList;
import supergp.wordmember.plan.TodayPlan;
import supergp.wordmember.quiz.DayChoose;
import supergp.wordmember.search.SearchList;

public class MainActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.tool_bar);
        setSupportActionBar(toolbar);

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
    }

    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        int id = item.getItemId();

        Intent intent;
        switch (id){
            case R.id.nav_lookup:
                intent = new Intent(MainActivity.this,SearchList.class);
                startActivity(intent);
                break;
            case R.id.nav_plan:
                intent = new Intent(MainActivity.this,TodayPlan.class);
                startActivity(intent);
                break;
            case R.id.nav_note:
                intent = new Intent(MainActivity.this,NoteList.class);
                startActivity(intent);
                break;
            case R.id.nav_quiz:
                intent = new Intent(MainActivity.this,DayChoose.class);
                startActivity(intent);
                break;
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
}
