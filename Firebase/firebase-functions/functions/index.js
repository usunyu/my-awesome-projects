const functions = require("firebase-functions");
const admin = require("firebase-admin");
admin.initializeApp();

// auth trigger (new user signup)
exports.newUserSignup = functions.auth.user().onCreate((user) => {
  // console.log("user created", user.email, user.uid);
  return admin.firestore().collection("users").doc(user.uid).set({
    email: user.email,
    upvotedOn: [],
  });
});

// auth trigger (user deleted)
exports.userDeleted = functions.auth.user().onDelete((user) => {
  // console.log("user deleted", user.email, user.uid);
  return admin.firestore().collection("users").doc(user.uid).delete();
});

// http callable function (adding a request)
exports.addRequest = functions.https.onCall((data, context) => {
  if (!context.auth) {
    throw new functions.https.HttpsError(
        "unauthenticated",
        "only authenticated users can add requests");
  }
  if (data.text.length > 30) {
    throw new functions.https.HttpsError(
        "invalid-argument",
        "request must be no more than 30 characters long");
  }
  return admin.firestore().collection("requests").add({
    text: data.text,
    upvotes: 0,
  });
});

// upvote callable function
exports.upvote = functions.https.onCall((data, context) => {
  // check auth state
  if (!context.auth) {
    throw new functions.https.HttpsError(
        "unauthenticated",
        "only authenticated users can upvote");
  }
  // get refs for user doc & request doc
  const user = admin.firestore().collection("users").doc(context.auth.uid);
  const request = admin.firestore().collection("requests").doc(data.id);
  return user.get().then((doc) => {
    // check user hasn't already upvoted the request
    if (doc.data().upvotedOn.includes(data.id)) {
      throw new functions.https.HttpsError(
          "failed-precondition",
          "you can only upvote something once");
    }
    // update user array
    return user.update({
      upvotedOn: [...doc.data().upvotedOn, data.id],
    })
        .then(() => {
          // update votes on the request
          return request.update({
            upvotes: admin.firestore.FieldValue.increment(1),
          });
        });
  });
});
