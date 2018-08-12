[TOC]



## WordMember背单词网站

### 前言

#### 项目简介

本次课程作业的内容为完成一个背单词网站。

根据现有流行的背单词软件，我们可以分析出现在广大英语学习用户人群的主要需求：单词的背诵、整理和复习。为了满足人们的这些需求，这门课程要求我们设计一款帮助英语学习用户背单词的网站。

网站的名字为WordMember，提供给用户单词查询、按计划复习、记录本整理、复习测验四个主要功能。网站同时配有Android手机客户端，可以非常方便地在不同情况下使用。虽然网页版与手机版的操作略有不同，不过他们都需要连接同一个服务器，并且发送相同的请求来完成对应的操作。



#### 使用手册

##### 注册与登陆

WordMember系统需要登录才可以正常使用。

对于新用户，在网站的欢迎界面点击Sign up按钮即可注册一个新的账户。注册账户的时候提供账户名、密码和邮箱。其中账户名和邮箱在系统中唯一，如果系统中已经存在该账户名或已经存在该邮箱，则需要更换用户名和邮箱进行注册。密码需要输入两次，且有安全性验证，长度小于6位的密码不予通过注册。

对于已经进行注册的用户，可以使用账户名和密码进行登录。当用户名和密码匹配的时候，会进入到WordMember的主界面中。如果用户忘记密码，则可以通过给出正确的email的方式重新设定密码。



##### 单词查询

WordMember提供单词查询功能，并且同时支持精准查询与模糊查询。精准查询即完整输入单词进行查询，模糊查询即使用'?'代替单个字母，使用'*'代替任意多个字母。提供这两种查询方式，可以满足用于绝大多数情况下对单词查询的需求。

查询结果会作为一个列表呈现在网页中，点击列表中的单词，即可进入单词详情界面进行学习。



##### 学习计划

WordMember可以为用户提供学习单词的功能。在用户刚完成注册的时候，用户并没有学习计划，这个时候点击按计划学习，会让用户选择单词集进行学习。目前在中考单词集中存有一些单词可供学习。由于缺少单词集资源，所以中考单词集中的单词为手动在数据库中添加的，作为测试使用。

选择单词集之后，即可进入学习。单词的学习分为8个词一组，当学习完一组单词之后，可以点击下一组。这个时候，当前的8个单词会加入到数据库中，在后续的若干天内复习多次。用户可以根据空闲时间长短自行决定要学习的单词的组数，这样更具有灵活性。



##### 单词本

WordMember为用户提供单词本的功能。在用户搜索单词和完成学习计划的时候，每个单词卡片上都有“加入单词本”按钮，点击按钮即可将卡片中的单词添加到单词本中。

在所有界面的顶部导航右侧，都有Note入口，可以在任何时候快速进入单词本查看。进入单词本界面后会显示单词本列表，点击对应的单词本，会进入单词本预览界面，即显示单词以及部分释义。点击单词既可以进入到单词的详细解释中进行查看。



##### 复习与测验

在完成当日学习计划之后，会需要在接下来的若干天内对这些单词进行复习。需要复习的单词按照艾宾浩斯记忆曲线给出。进入复习与测验界面时，日期选择器选择当前日期，并给出需要复习的单词。当选择其他日期的时候，会给出所选日期应当复习的单词。

WordMember中记忆曲线具体工作方式如下：在刚完成某个单词的学习时，在数据库中新增对该单词的学习记录，并保存学习的日期，设置已复习次数为0。然后在第一个记忆周期（1天）后给出第一次复习。如果用户正确完成了测验，则已复习次数自增1。以此类推，接下来的记忆周期和已复习次数的对应关系为第二个记忆周期（2天，已复习次数1）、第三个记忆周期（4天，已复习次数2）、第四个记忆周期（7天，已复习次数3）。每个单词在复习四次之后可以认为用户已经学会该单词，不再对其进行测验。

如果用户觉得某个词掌握特别不熟，可以在测验的时候将其加入单词本，主动对其进行复习。



### 网站设计

#### 整体设计

网站采用前后端分离的方式进行设计，前后端使用http请求进行连接。这样的好处是在完成网页端的设计之后，可以较为容易地完成手机客户端的设计。http请求是现在大型系统设计时候的常用连接方式，在网页端和安卓端都有很好的封装库可供使用。所以，在完成背单词系统逻辑设计之后，只要将所需的请求加入前端的代码中，即可完成全部的功能。



#### 前端设计

##### 界面设计

前端界面在开发的时候分为了两个阶段。在最开始设计登录注册界面时，套用了模板完成。在进入主界面之后，由于模板的样式太少，不得不放弃继续套用模板的想法，转为使用materialize库自行设计网页主体。

套用模板完成的界面为登录注册界面和登录之后的主界面。

登录界面为了追求视觉美感，采用了这款动态特效的模板，提供登录、注册和忘记密码三个功能。其中注册界面和忘记密码界面采用相同的模板，在此不重复截图。

![1530117809105](E:\学习\上课\BS\src\1530117809105.png)

登录之后的主界面采用了一个较为美观的带有导航栏的模板，将整个界面分为三个部分：单词查询、学习单词、记录本与测验。通过点击最上方的导航栏可以快速跳到对应的部分进行下一步操作。

其中记录本与测验放在了同一个部分中，这个是由一开始的设计导致的。最初的设计是将用户的所有单词本都放到主界面的这个部分，但是在后续开发过程中无意间完成了单词本列表这个界面和相关逻辑，所以在主界面中就只加入了进入单词本这一个入口，并将其与测验放在了一起。

![1530118180052](E:\学习\上课\BS\src\1530118161153.png)

![1530118203346](E:\学习\上课\BS\src\1530118203346.png)

![1530118217313](E:\学习\上课\BS\src\1530118217313.png)

接下来的各种功能界面都采用了materialize的UI库，使用其提供的组件来完成对应的功能。在接下来的所有界面中，都有顶部的导航栏，可以快速进入单词本界面或者快速登出来切换账号。

首先是单词查询的界面。输入单词，点击搜索即可进行搜索。搜索结果会显示在下方的列表中，对于精确搜索，列表中只会显示一条记录，对于模糊搜索，列表中会显示全部的匹配。

![1530118480167](E:\学习\上课\BS\src\1530118480167.png)

点击列表中的单词，即可进入单词详细信息界面。

![1530118684455](E:\学习\上课\BS\src\1530118684455.png)

然后是学习单词界面。单词学习界面使用这种滚动查看的方式将单词卡片提供给用户，可以产生较好的视觉体验。点击下一组即学习完当前的八个单词，这些单词会被加入用户学习记录中，供后续复习使用。

![1530118724678](E:\学习\上课\BS\src\1530118724678.png)

进入单词本界面，会显示该用户的全部单词本，也可以新增单词本。

![1530178088342](E:\学习\上课\BS\src\1530178088342.png)

点击要进入的单词本，即可查看单词本中的单词列表。

![1530178201695](E:\学习\上课\BS\src\1530178201695.png)

点击单词也可以进入单词的详细信息界面，这里不重复截图。

进入复习与测验界面，默认选择当前日期，用户也可以选择其他日期进行复习。

![1530178415218](E:\学习\上课\BS\src\1530178342046.png)

确定日期之后，即可进行练习，根据汉语解释填写英文单词，如果忘记该单词，可以查看提示。

![1530198067809](E:\学习\上课\BS\src\1530198067809.png)



##### 前端逻辑设计

前端逻辑部分采用纯js代码完成。

发送http请求的基本格式如下：

```js
$.ajax({
    data: "request",
    url: 'http://127.0.0.1:4497',
    dataType: "jsonp",
    jsonp: "callback",
    jsonpCallback: "success_jsonpCallback"
}).done(function (res) {
    console.log(res);
});
```

前端逻辑主要在于为界面组件设置值，其中较为重要一点为navbar中的用户名。

```js
if(window.location.href.substr(-1)==="#")
    window.location.href = window.location.href.substr(0, window.location.href.length-1);
let paras = window.location.href.split('?');
let id = "";
if(paras.length > 1) {
    paras = paras[1].split('&');
    id = paras[0];
    id = uncompile(id);

    if(id.split('=')[1] === undefined)
        logOut();
    if(document.getElementById("userid"))
        document.getElementById("userid").innerText = 'User:' + id.split('=')[1];

    for(let i = 1; i < paras.length; i++){
        paras[i] = uncompile(paras[i]);
    }
}
```

对于非公用的js代码，将其写在对应html的script标签中。以单词详细信息界面为例。界面初始化的时候解析url(url在传输的时候进行加密)，从url中获取需要查询的单词，然后发送查询该单词的请求。获取到查单词请求的返回值的时候，将释义和例句显示到单词卡片上。

```js
$.ajax({
    data: "word_search&" + paras[1].split('=')[1],
    url: 'http://127.0.0.1:4497',
    dataType: "jsonp",
    jsonp: "callback",
    jsonpCallback: "success_jsonpCallback"
}).done(function (res) {
    let tmp = JSON.parse(res);
    document.getElementById("title").innerText=tmp.word;
    document.getElementById("trans").innerText=tmp.trans;
    document.getElementById("examp").innerText=tmp.examp;
});
```

其他界面的逻辑类似，核心都在请求的发送和返回值的处理中。



#### 后端设计

##### 数据库设计

数据库使用mySql，在后端可以方便地连接并操作数据库。

系统中的数据库分为固定数据库(存储用户的身份和学习信息)和动态数据库(存储每个用户的单词本)。固定数据库为users、milestone、memrecord以及midexam、highexam等单词集，动态数据库为名字形如id_note_name的用户单词本。

各固定数据库设计如下：

users存储用户的账户、密码和电子邮箱地址。

```sql
CREATE TABLE `users` (
  `id` varchar(40) NOT NULL,
  `password` varchar(40) DEFAULT NULL,
  `email` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `email_UNIQUE` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 PACK_KEYS=1;
```

milestone存储用户当前的学习进度，即在学习哪个单词集，已完成学习的数量。

```sql
CREATE TABLE `milestone` (
  `id` varchar(40) NOT NULL,
  `wordset` varchar(20) DEFAULT NULL,
  `base` int(11) DEFAULT NULL,
  `step` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

memrecord存储用户的全部学习足迹及其时间戳，即一条记录为用户在某一天学习了某一个单词。

```sql
CREATE TABLE `memrecord` (
  `row` int(11) NOT NULL AUTO_INCREMENT,
  `id` varchar(40) NOT NULL,
  `wordset` varchar(20) NOT NULL,
  `num` int(11) DEFAULT NULL,
  `stamp` date DEFAULT NULL,
  `reviewed` int(11) DEFAULT NULL,
  PRIMARY KEY (`row`),
  UNIQUE KEY `row_UNIQUE` (`row`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;
```

单词集数据库以midexam为例，存储该单词集中的单词。

```sql
CREATE TABLE `midexam` (
  `word` varchar(20) DEFAULT NULL,
  `num` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`num`),
  UNIQUE KEY `num_UNIQUE` (`num`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;
```

此种数据库设计方式可以完成目前该背单词网站的全部需求，使用mySql服务器提供给后端程序访问，后端程序执行sql代码来获取其所需的数据。



##### 后端逻辑设计

后端采用node运行环境，获取前端发送的http请求，根据请求的内容来操作数据库并给出返回值。

总结用到的全部请求。

```doc
login_req:登录请求
sign_req:注册请求
repass_req:修改密码请求
word_search:查询单词请求
find_plan:获取用户当前单词集请求
add_plan:设置用户当前单词集请求
fetch_plan:获取当前计划下的一组单词
finish_learn:完成一组学习计划请求
create_note:创建单词本请求
add_note:单词加入单词本请求
note_list:获取单词本列表
note_words:获取单词本中的单词请求
get_quiz:获取需要测验的单词请求
quiz_right:测验正确请求
quiz_wrong:测验错误请求
```

对于大部分请求，首先获取请求中的数据，然后进入数据库中查询。

查询单词释义逻辑与此不同，由于单词及解释信息存储在本地的dict.all文件中，所以设计的逻辑为在服务器开启的时候加载该词典，然后在查询的时候直接在内存中查询。

为了加速查询，单词的精确查询使用二分查找，单词的模糊查询使用通配符递归。

```js
function singleSearch(word, begin, end){
    if(begin>=end-1){
        if(word===words[begin].word)return JSON.stringify(words[begin]);
        return JSON.stringify("");
    }
    if(word===words[Math.floor((begin+end)/2)].word.toLowerCase())return JSON.stringify(words[Math.floor((begin+end)/2)]);
    else if(word > words[Math.floor((begin+end)/2)].word.toLowerCase())return singleSearch(word, Math.floor((begin+end)/2), end);
    else return singleSearch(word, begin, Math.floor((begin+end)/2));
}
function multiSearch(word){
    let res = [];
    words.forEach(function(item){
        if(searchMeet(item.word, word))
            res.push(item);
    });
    return JSON.stringify(res);
}
```



### 网站测试

#### 功能测试

对WordMember的注册登录和四个主要功能进行测试。

首先是注册登录功能，注册一个新账户test，密码为123456，然后登录。

![1530241537081](E:\学习\上课\BS\src\1530241491287.png)

![1530241597581](E:\学习\上课\BS\src\1530241597581.png)

然后测试查单词功能，精确查询word，模糊查询w?r*。

![1530241738238](E:\学习\上课\BS\src\1530241738238.png)

![1530241720898](E:\学习\上课\BS\src\1530241720898.png)

选择一个条目查看单词详细信息。

![1530241836870](E:\学习\上课\BS\src\1530241836870.png)

接下来测试学习计划，由于是新账户，需要选择单词集进行学习，这里选择中考单词，里面有24个手动加入的单词，然后学习一组单词。

![1530242034090](E:\学习\上课\BS\src\1530242034090.png)

![1530242076099](E:\学习\上课\BS\src\1530242076099.png)

点击下一组，即表示学习完成这一组单词，然后进入测试功能。

![1530242125253](C:\Users\MLKJ\AppData\Local\Temp\1530242125253.png)

由于当天学习的单词无需测验，所以将日期调至下一天即可提前进行测试。

![1530242223693](C:\Users\MLKJ\AppData\Local\Temp\1530242223693.png)

最后测试单词本功能，首先创建单词本abc，然后加入学习计划中的若干词汇。

![1530242303742](E:\学习\上课\BS\src\1530242303742.png)

进入单词本查看所加入的单词。

![1530242326438](E:\学习\上课\BS\src\1530242326438.png)

功能测试符合预期。



#### 边界测试

常见的边界测试有注册输入非法、sql注入等等。

WordMember中加入了对sql注入的预防。

```js
if(data[2].indexOf(';')!==null || data[2].indexOf('\"')!==null||
    data[3].indexOf(';')!==null || data[3].indexOf('\"')!==null){
    res.writeHead(200, {'Content-Type': 'application/json'});
    let json = JSON.stringify('danger');
    res.end('success_jsonpCallback(' + json + ')');
}
```

不过，由于数据库本身的安全机制的防护，后端node代码无法一次执行多条sql查询，即从根源上阻断了sql注入的发生。



#### 性能测试

对性能进行测试，计划连续发送100条某请求，观察服务器的响应效果。

经过测试，发送100条请求用时104ms，由于发送请求的逻辑为串行执行，所以可以认为一条请求的平均用时为1ms左右。这个速度对于背单词网站而言是足够满足用户需求的。



### 手机客户端

#### 前端设计

WordMember实现了安卓客户端应用程序，逻辑与功能与网页端相同。因为安卓自身的封装做的很好，所以在开发的时候没有使用任何第三方的库，而是直接使用安卓原生的组件来开发。

界面设计较为简洁，功能一目了然。

进入软件首先登陆，使用刚注册的账户test进行登录。

![1530242627718](E:\学习\上课\BS\src\1530242627718.png)

登录之后进入查单词模块，查询单词word。

![1530242661571](E:\学习\上课\BS\src\1530242661571.png)

![1530242691796](E:\学习\上课\BS\src\1530242691796.png)

然后进入学习计划功能，所呈现的功能与网页端类似。

![1530242755934](E:\学习\上课\BS\src\1530242738495.png)

然后测试复习功能。

![1530243202311](E:\学习\上课\BS\src\1530243202311.png)

选择30日，然后进入测试。

![1530243237623](E:\学习\上课\BS\src\1530243237623.png)

至此完成安卓端的主要功能。由于时间原因，安卓端并没有实现网页端的全部功能，在今后的空闲时间我会加以完善。



#### 功能设计

安卓端也是以发送http请求来完成全部的功能的。这里实现了一个专用类，用来向服务器发送请求。

```java
public class HttpReq {
    static public String getReq(String url, String param){
        String result = "";

        String baseURL = "http://192.168.1.184:4497";
        url = baseURL + url + "?takeup&" + param;
        try {
            URL conn = new URL(url);
            HttpURLConnection urlConn = (HttpURLConnection)conn.openConnection();
            InputStreamReader in = new InputStreamReader(urlConn.getInputStream());
            BufferedReader bufferedReader = new BufferedReader(in);
            String tmp;
            while((tmp = bufferedReader.readLine())!=null){
                result += tmp;
            }
            in.close();
            urlConn.disconnect();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result.substring(22, result.length()-1);
    }
}
```

由于运行服务器的PC连接在寝室的路由器上，所以从ipconfig中获取的地址为私网地址，时间紧迫没能在主界面中加入动态更改服务器地址的方法。

对于每个界面，编写一个界面Java类，为其中的按钮加入响应函数。响应函数的主要作用即发送请求，然后将返回的结果显示在屏幕上。以查单词请求为例。

```java
public class WordDetail extends AppCompatActivity{

    private Handler handler =new Handler() {
        @Override
        public void handleMessage(Message msg) {
            TextView word = (TextView)findViewById(R.id.title);
            TextView trans = (TextView)findViewById(R.id.trans);
            TextView examp = (TextView)findViewById(R.id.examp);
            if (word != null) {
                word.setText(msg.getData().getString("word"));
            }
            if (trans != null) {
                trans.setText(msg.getData().getString("trans"));
            }
            if (examp != null) {
                examp.setText(msg.getData().getString("examp"));
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_word);

        Button search = (Button)findViewById(R.id.search);
        if (search != null) {
            search.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    final EditText input = (EditText)findViewById(R.id.input);
                    if (input != null) {
                        new Thread(new Runnable(){
                            @Override
                            public void run() {
                                String res = HttpReq.getReq("", "word_search&" + input.getText());
                                res = res.substring(1, res.length()-1);
                                try {
                                    res = res.replace("\\\"", "\"");
                                    res = res.replace("\\\\", "\\");
                                    JSONObject jsonObject=new JSONObject(res);
                                    String word = jsonObject.getString("word");
                                    String trans = jsonObject.getString("trans");
                                    String examp = jsonObject.getString("examp");

                                    Message msg = new Message();
                                    Bundle bundle = new Bundle();
                                    bundle.putString("word",word);
                                    bundle.putString("trans",trans);
                                    bundle.putString("examp",examp);
                                    msg.setData(bundle);
                                    handler.sendMessage(msg);
                                } catch (JSONException e) {
                                    e.printStackTrace();
                                }
                            }

                        }).start();
                    }
                }
            });
        }
    }
}
```

其他界面类与其类似。



### 总结与体会

我十分认真地完成了这次课程作业，也是我第一次独立开发一个网页端和移动端的系统。在编写网站的过程中，我深入了解了Browser-Server的体系，也获得了许多实用的经验。

我很早就开始了这个系统的编写，期中之前，我就设计好了需求，并完成了部分网站的内容。最先完成的是网页的前端部分。在最开始，由于缺乏信心，我的网页是套用模板完成的。不过，在修改模板内容的时候，我渐渐了解了html、js和css的原理，也能根据自己的需求来调整页面内的元素了。

我使用模板完成了注册和登录界面。在这之后，由于需求渐渐增多，使用模板已经无法完成后续的工作。于是，我开始使用现在较为流行的materialize的UI库。这个库为我们提供了许多组件，将组件放置在页面中即可使用。于是，我使用这个UI库完成了剩余的全部界面。

完成大部分前端之后，我开始编写后端。

我尝试了多种构建服务器的方式，如C++和Java等等，我最初是计划使用socket传输数据的，不过前端不允许这样的操作。最终，经过了很多次的失败，我开始使用node框架来传输http请求。这次，前后端的连接变得顺利了许多。在前后端连接建立好之后，我就可以方便地向这个系统中加入不同类型的请求了。

在此之后，前端逻辑和后端逻辑就是同步编写的了，每加入一种请求的类型，就要为其编写对应的前端和后端逻辑。这个过程随着网站的逐渐完善变得越来越公式化了。我相信，如果今后还需要我来完成一个node框架下的网站，我可以更加熟练地完成。

完成网页端全部功能之后，我开始实现安卓端的功能。这个时候所剩时间已经不多了，所以我抓住重点的几个功能来实现。由于我对安卓较为熟悉，所以我在较短的时间内完成了安卓程序的开发。

这个学期的另外一门课程，软件工程，也是要求完成一个网站系统。讨论之后小组决定使用django框架。现在，这门课的背单词网站和软件工程课的教务管理网站都已经完成，我也掌握了node和django两个市场流行的框架。我确信，在今后的网站开发工作中，我会更加有信心，更加熟练，也可以指导其他组员一起来完成我们的工作。当然，网站是B/S架构的，我对这个体系架构的理解也变得更加的深入了。



