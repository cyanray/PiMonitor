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
$s = 'insert into RoomState (Temp,Hum,time) VALUES ("'.$_POST["Temp"].'","'.$_POST["Hum"].'","'.date("Y-m-d h:i:s").'");';
//echo $s;
$result = $conn->query($s);

if($result===TRUE)
{
    echo 'OK.';
}
else
{
    echo $conn->error;
}
$conn->close();
?>
