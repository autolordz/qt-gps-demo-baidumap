<script type="text/javascript" src="http://api.map.baidu.com/api?key=46ce9d0614bf7aefe0ba562f8cf87194&v=1.0&services=true"></script>
</head>
<body>
<div style="width:520px;height:340px;border:1px solid gray" id="container">
</div>
</body>
</html>
<script type="text/javascript">
var map = new BMap.Map("container");
var point = new BMap.Point(113.562447, 22.256915);
map.centerAndZoom(point, 15);
var marker = new BMap.Marker(point);        // 创建标注
map.addOverlay(marker);                          // 将标注添加到地图中
</script>