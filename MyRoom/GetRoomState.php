<?php
$servername = "localhost";
$username = "cyan";
$password = "cyancyan";

// 创建连接
$conn = new mysqli($servername, $username, $password,"piMonitor");
// 检测连接
if ($conn->connect_error) {
    die("连接失败: " . $conn->connect_error);
}
$s = 'Select Temp,time From RoomState;';
//echo $s;
$result = $conn->query($s,MYSQLI_USE_RESULT);

$rows = array();
while($r = mysqli_fetch_array($result)) {
  $rows[] = $r;
}
echo json_encode($rows);

$conn->close();
?>
