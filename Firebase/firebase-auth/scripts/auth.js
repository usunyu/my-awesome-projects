// listen for auth state change
auth.onAuthStateChanged(user => {
  if (user) {
    // console.log('user logged in:', user);
    // get data
    db.collection('guides').onSnapshot((snapshot) => {
      console.log('onSnapshot change');
      setupGuides(snapshot.docs);
    });
  }
  else {
    // console.log('user logged out');
    setupGuides([]);
  }
  setupUI(user);
});

// create new guide
const createForm = document.querySelector("#create-form");
createForm.addEventListener('submit', e => {
  e.preventDefault();

  db.collection('guides').add({
    'title': createForm['title'].value,
    'content': createForm['content'].value,
  }).then(() => {
    const modal = document.querySelector('#modal-create');
    M.Modal.getInstance(modal).close();
    createForm.reset();
  }).catch(err => {
    console.log(err.message);
  });
});

// signup
const signupForm = document.querySelector('#signup-form');
signupForm.addEventListener('submit', (e) => {
  e.preventDefault();

  // get user info
  const email = signupForm['signup-email'].value;
  const password = signupForm['signup-password'].value;

  // signup the user
  auth.createUserWithEmailAndPassword(email, password).then((cred) => {
    const modal = document.querySelector('#modal-signup');
    M.Modal.getInstance(modal).close();
    signupForm.reset();
  });
});

// logout
const logout = document.querySelector('#logout');
logout.addEventListener('click', (e) => {
  e.preventDefault();
  auth.signOut();
});

const loginForm = document.querySelector('#login-form');
loginForm.addEventListener('submit', (e) => {
  e.preventDefault();

  // get user info
  const email = loginForm['login-email'].value;
  const password = loginForm['login-password'].value;

  // log user in
  auth.signInWithEmailAndPassword(email, password).then((cred) => {
    // console.log(cred.user);

    const modal = document.querySelector('#modal-login');
    M.Modal.getInstance(modal).close();
    loginForm.reset();
  });
});